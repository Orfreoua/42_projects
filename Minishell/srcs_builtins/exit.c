/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 00:15:31 by orfreoua          #+#    #+#             */
/*   Updated: 2022/12/09 15:03:42 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_exit(t_exec *exec, t_data *data)
{
	free_tab(exec->env);
	free_pipe(exec);
	free(exec->pipe.cmd);
	gest_error(END, data);
	free_heredoc(exec);
	ft_putstr_fd(2, "exit\n");
	exit(g_exit_ret);
}

int	nb_args_cmd(t_exec *exec)
{
	int	i;

	i = 0;
	while (exec->pipe.cmd_splited[i])
		i++;
	return (i);
}

int	is_not_digital_arg(char *arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	if (arg[0] == '-')
		i++;
	while (arg[i] && ft_isdigit(arg[i]))
		i++;
	if (arg[i])
		return (1);
	return (0);
}

void	builtin_exit(t_exec *exec, t_data *data)
{
	if (nb_args_cmd(exec) < 2 && exec->pipe.nb_pipe == 0)
		free_exit(exec, data);
	if (ft_strlen(exec->pipe.cmd_splited[1]) >= 20
		|| is_not_digital_arg(exec->pipe.cmd_splited[1]))
	{
		ft_putstr_fd(STDERR_FILENO, "minishell : exit : ");
		ft_putstr_fd(STDERR_FILENO, exec->pipe.cmd_splited[1]);
		ft_putstr_fd(STDERR_FILENO, ": numeric argument required\n");
		if (!exec->pipe.nb_pipe)
		{
			g_exit_ret = 2;
			free_exit(exec, data);
		}
	}
	if (nb_args_cmd(exec) > 2)
	{
		ft_putstr_fd(STDERR_FILENO, "minishell : exit : ");
		ft_putstr_fd(STDERR_FILENO, "too many arguments\n");
		return ;
	}
	if (!exec->pipe.nb_pipe)
	{
		g_exit_ret = ft_atoi((const char *)exec->pipe.cmd_splited[1]);
		free_exit(exec, data);
	}
}
