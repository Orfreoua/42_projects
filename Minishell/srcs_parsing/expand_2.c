/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:19:15 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/30 20:41:58 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

char	*ft_strcopy_spec(char *str, int j)
{
	char	*cpy;

	cpy = malloc ((3) * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	cpy[0] = '$';
	cpy[1] = str[j];
	cpy[2] = '\0';
	return (cpy);
}

char	**add_one_str(char **exp, char *str)
{
	char	**cpy;
	int		i;	

	i = 0;
	cpy = malloc ((ft_strstrlen(exp) + 2) * sizeof(char *));
	while (exp != NULL && exp[i] != NULL)
	{
		cpy[i] = exp[i];
		i++;
	}
	cpy[i] = str;
	i++;
	cpy[i] = NULL;
	free(exp);
	return (cpy);
}

int	found_split(char *s, int dollar, int j, int i)
{
	if (dollar == 0)
	{
		if (s[i] == '$')
			return (FOUND);
	}
	else
	{
		if (j + 1 == i && (ft_num(s[i]) == FOUND || (s[i] == '?')))
			return (SPEC);
		else if (ft_maj(s[i]) == N_FOUND && ft_min(s[i]) == N_FOUND
			&& ft_num(s[i]) == N_FOUND && s[i] != '_')
			return (FOUND);
	}
	return (N_FOUND);
}

void	change_dollar(char *str, int *dollar, int i)
{
	if (str[i] == '$')
		(*dollar) = 1;
	else
		(*dollar) = 0;
}

char	**select_found(int cpt[3], int *dollar, char **exp, char *str)
{
	if (cpt[2] == FOUND)
	{
		exp = add_one_str(exp, ft_strcopy_i_j(str, cpt[1], cpt[0]));
		cpt[1] = cpt[0];
	}
	else
	{
		exp = add_one_str(exp, ft_strcopy_spec(str, cpt[0]));
		cpt[1] = cpt[0] + 1;
	}
	change_dollar(str, dollar, cpt[0]);
	return (exp);
}
