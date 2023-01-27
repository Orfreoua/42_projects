/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 00:22:14 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/30 20:45:38 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

char	*dollar_case(char **exp, int i)
{
	char	*ret;

	ret = malloc(2 * sizeof(char));
	ret[0] = '$';
	ret[1] = '\0';
	free(exp[i]);
	return (ret);
}

char	*n_found_case(char **exp, int i)
{
	char	*ret;

	ret = malloc(2 * sizeof(char));
	ret[0] = '\0';
	free(exp[i]);
	return (ret);
}

char	*switch_env_case(char **exp, char **env, int j, int i)
{
	int		k;

	k = 0;
	while (env[i][k] != '=')
		k++;
	k++;
	free(exp[j]);
	return (ft_strcopy_int(env[i], &k));
}

char	*modif_exp(char **exp, int j, char **env)
{
	int	i;

	while (exp[j] != NULL)
	{
		if (exp[j][0] == '$' && exp[j][1] == '\0')
			exp[j] = dollar_case(exp, j);
		else if (exp[j][0] == '$' && exp[j][1] == '?')
			exp[j] = interro_case(exp, j);
		else if (exp[j][0] == '$')
		{
			i = ft_strstrcmp(env, exp[j]);
			if (i == ERROR)
				exp[j] = n_found_case(exp, j);
			else
				exp[j] = switch_env_case(exp, env, j, i);
		}
		j++;
	}
	return (ft_strrjoin(exp));
}

void	ft_expand(t_data *data, char **env)
{
	char	**exp;
	int		i;

	i = 0;
	exp = ft_split_exp(data->str);
	free(data->str);
	data->str = modif_exp(exp, i, env);
}
