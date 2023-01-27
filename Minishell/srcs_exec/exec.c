/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:07:58 by orfreoua          #+#    #+#             */
/*   Updated: 2022/12/09 15:08:03 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	exec_pipe(t_data *data, t_exec *exec, int cpt_pipe)
{
	redir(data, exec, cpt_pipe);
	signal_catching_mode(CHILD_PROCESS);
	if (cpt_pipe < exec->pipe.nb_pipe)
		dup2(exec->pipe.fd_pipe[1], STDOUT_FILENO);
	if (exec->pipe.prev != -1)
		dup2(exec->pipe.prev, STDIN_FILENO);
	if (exec->pipe.fd_pipe[0] > 0)
		close(exec->pipe.fd_pipe[0]);
	if (exec->pipe.fd_pipe[1] > 0)
		close(exec->pipe.fd_pipe[1]);
	if (is_builtin(exec->pipe.cmd_splited[0]))
		do_builtin(exec, exec->pipe.cmd_splited);
	else if (ft_strlen(exec->pipe.cmd_splited[0]))
	{
		execve(exec->pipe.path_cmd,
			exec->pipe.cmd_splited, exec->env);
		print_error_cmd(exec);
		exit(127);
	}
	exit(g_exit_ret);
}

int	load_pipe(t_data *data, t_exec	*exec, int cpt_pipe)
{
	pid_t	pid;

	if (is_builtin(exec->pipe.cmd_splited[0]))
		builtins_before_pipe(exec, &exec->pipe.cmd_splited[0], data);
	pid = fork();
	if (pid)
	{
		signal_catching_mode(PARENT_PROCESS);
		if (exec->pipe.prev > 0)
		{
			close(exec->pipe.prev);
			exec->pipe.prev = -1;
		}
		if (exec->pipe.fd_pipe[1] != -1)
		{
			close(exec->pipe.fd_pipe[1]);
			exec->pipe.fd_pipe[1] = -1;
		}
	}
	else
		exec_pipe(data, exec, cpt_pipe);
	return (OK);
}

int	hd_error(t_data *data, t_exec *exec)
{
	free_tab(exec->env);
	gest_error(END, data);
	return (ERROR);
}

int	ctrl_c_hd(t_data *data)
{
	gest_error(END, data);
	g_exit_ret = 130;
	return (OK);
}

int	execution(t_data *data, t_exec *exec)
{
	int			i;

	if (load_heredoc(data, exec) == ERROR)
		hd_error(data, exec);
	if (g_exit_ret == 424242)
		return (ctrl_c_hd(data));
	exec->pipe.nb_pipe = count_nb_pipe(data);
	i = 0;
	while (i < exec->pipe.nb_pipe + 1)
	{
		exec->pipe.prev = exec->pipe.fd_pipe[0];
		if (i < exec->pipe.nb_pipe)
		{
			if (pipe(exec->pipe.fd_pipe) == -1)
				return (print_error("pipe failed, execution()"));
		}
		if (load_struct_pipe(data, exec, i) == ERROR)
			return (print_error("load_pipe()"));
		load_pipe(data, exec, i++);
		free_pipe(exec);
	}
	return (free_history_end(exec, data, i));
}
