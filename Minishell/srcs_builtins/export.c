/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:17:39 by orfreoua          #+#    #+#             */
/*   Updated: 2022/09/17 23:17:44 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	already_exists(char **env, char *s, int n)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], s, n))
			return (i);
		i++;
	}
	return (-1);
}

int	change_value(t_exec *exec, char *s, int line)
{
	free_string(exec->env[line]);
	exec->env[line] = ft_strdup(s);
	if (!exec->env[line])
		return (ERROR);
	return (OK);
}

int	generate_new_line(t_exec *exec, char *s)
{
	char	**new_env;
	int		i;

	i = 0;
	while (exec->env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (ERROR);
	i = 0;
	while (exec->env[i])
	{
		new_env[i] = ft_strdup(exec->env[i]);
		if (!new_env[i])
			return (free_tab_error(new_env, i));
		i++;
	}
	new_env[i] = ft_strdup(s);
	if (!new_env[i])
		return (free_tab_error(new_env, i));
	new_env[i + 1] = 0;
	free_tab(exec->env);
	exec->env = new_env;
	return (OK);
}

void	pre_export(t_exec *exec)
{
	char	*new_s;
	int		i;

	i = 1;
	while (exec->pipe.cmd_splited[i])
	{
		new_s = ft_strdup(exec->pipe.cmd_splited[i]);
		builtin_export(exec, new_s);
		free(new_s);
		new_s = NULL;
		i++;
	}
}

int	builtin_export(t_exec *exec, char *s)
{
	int	i;
	int	line;

	i = 0;
	if (!ft_isalpha(s[0]) && s[0] != '_')
		return (error_export(s));
	while (s[i])
	{
		if (s[i] == '=')
		{
			if (s[i - 1] == ' ')
				ft_putstr_fd(STDERR_FILENO,
					"minishell: export: No such file or directory\n");
			line = already_exists(exec->env, s, i);
			if (line != -1)
				return (change_value(exec, s, line));
			else
				return (generate_new_line(exec, s));
		}
		i++;
	}
	return (OK);
}
