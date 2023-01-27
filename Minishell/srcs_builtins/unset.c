/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:18:07 by orfreoua          #+#    #+#             */
/*   Updated: 2022/09/17 23:18:08 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	delete_line(t_exec *exec, int line_to_delete)
{
	char	**new_env;
	int		i;
	int		j;

	i = 0;
	while (exec->env[i])
		i++;
	new_env = malloc(sizeof(char *) * i);
	i = 0;
	j = 0;
	while (exec->env[j])
	{
		if (j != line_to_delete)
		{
			new_env[i] = ft_strdup(exec->env[j]);
			if (!new_env[i])
				return (free_tab_error(new_env, i));
			i++;
		}
		j++;
	}
	new_env[i] = 0;
	free_tab(exec->env);
	exec->env = new_env;
	return (OK);
}

void	pre_unset(t_exec *exec)
{
	char	*new_s;
	int		i;

	i = 1;
	while (exec->pipe.cmd_splited[i])
	{
		new_s = ft_strdup(exec->pipe.cmd_splited[i]);
		builtin_unset(exec, new_s);
		free(new_s);
		new_s = NULL;
		i++;
	}
}

int	builtin_unset(t_exec *exec, char *name)
{
	int		i;

	i = 0;
	while (exec->env[i])
	{
		if (!ft_strncmp(exec->env[i], name, ft_strlen(name)))
			return (delete_line(exec, i));
		i++;
	}
	return (OK);
}
