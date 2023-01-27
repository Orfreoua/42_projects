/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:32:18 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/30 20:42:35 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

int	ft_strcmp(char *env, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && env[i] != '\0' && str[i] == env[i])
		i++;
	if (str[i] == '\0' && env[i] == '=')
		return (FOUND);
	return (N_FOUND);
}

int	ft_strcmp_i(char *env, char *str, int i)
{
	int	j;

	j = 0;
	while (str[i] != '\0' && env[j] != '\0' && str[i] == env[j])
	{
		i++;
		j++;
	}
	if (str[i] == '\0' && env[j] == '=')
		return (FOUND);
	return (N_FOUND);
}

int	ft_strstrcmp(char **env, char *str)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strcmp_i(env[i], str, 1) == FOUND)
			return (i);
		i++;
	}
	return (ERROR);
}

char	*ft_strrjoin(char **str)
{
	int		len;
	char	*cpy;
	int		i;
	int		j;

	len = ft_strllen(str);
	cpy = malloc((len + 1) * sizeof(char));
	len = 0;
	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			cpy[len] = str[i][j];
			len++;
			j++;
		}
		i++;
	}
	cpy[len] = '\0';
	free_str(str);
	return (cpy);
}
