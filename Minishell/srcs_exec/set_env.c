/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:55:39 by orfreoua          #+#    #+#             */
/*   Updated: 2022/12/09 14:55:46 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	replace_shlvl(char **new_env)
{
	int	i;

	i = 0;
	while (new_env[i])
	{
		if (!ft_strncmp(new_env[i], "SHLVL=", 6))
			replace_string_on_tab(new_env, i, "SHLVL=42");
		if (!new_env[i])
		{
			free_tab(new_env);
			print_error("malloc failed 1, replace_shlvl()");
		}
		i++;
	}
}

char	**free_env_error(char **new_env, int index_free)
{
	print_error("malloc failed, set_empty_env()");
	if (index_free > 1)
		free(new_env[1]);
	if (index_free > 0)
	{
		free(new_env[0]);
		free(new_env);
	}
	return (NULL);
}

char	**set_empty_env(void)
{
	char	**new_env;

	new_env = malloc(sizeof(char *) * 3);
	if (!new_env)
		return (free_env_error(new_env, 0));
	new_env[0] = ft_strdup("PWD=");
	if (!new_env[0])
		return (free_env_error(new_env, 1));
	new_env[0] = ft_strjoin(new_env[0], fill_pwd(), 1);
	if (!new_env[0])
		return (free_env_error(new_env, 1));
	new_env[1] = ft_strdup("SHLVL=42");
	if (!new_env[1])
		return (free_env_error(new_env, 2));
	new_env[2] = 0;
	return (new_env);
}

char	**set_env(char **env)
{
	char	**new_env;

	if (!env[0])
		return (set_empty_env());
	new_env = ft_tabdup(env);
	if (!new_env)
	{
		print_error("malloc failed, set_env()");
		return (NULL);
	}
	replace_shlvl(new_env);
	return (new_env);
}
