/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:27:20 by orfreoua          #+#    #+#             */
/*   Updated: 2022/11/02 17:27:22 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minishell.h"

int	g_exit_ret;

int	init_exec(t_exec *exec)
{
	exec->pipe.fd_pipe[0] = -1;
	exec->pipe.fd_pipe[1] = -1;
	exec->pipe.cmd = NULL;
	exec->pipe.path_cmd = NULL;
	exec->pipe.cmd_splited = NULL;
	exec->nb_execution = 1;
	exec->hd.nb = 0;
	exec->hd.tab_fd = NULL;
	exec->hd.tab_of_name_file = NULL;
	exec->hd.tab_exit_code = NULL;
	g_exit_ret = 0;
	exec->status = 0;
	exec->hd.cpt_close = 0;
	return (OK);
}

void	routine(t_exec *exec, char *line)
{
	t_data	*data;

	while (1)
	{
		exec->pipe.fd_pipe[0] = -1;
		exec->pipe.fd_pipe[1] = -1;
		if (!line)
		{
			free_tab(exec->env);
			exit(g_exit_ret);
		}
		add_history(line);
		data = parsing(line, exec->env);
		if (data)
		{
			if (execution(data, exec) == ERROR)
			{
			}
		}
		free_string(line);
		line = readline("minishell : ");
		exec->nb_execution++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_exec				exec;
	char				*line;

	(void)argc;
	(void)argv;
	exec.env = set_env(env);
	if (!exec.env)
		return (print_error("malloc failed, set_env()"));
	init_exec(&exec);
	signal_catching_mode(INTERACTIVE);
	line = readline("minishell : ");
	routine(&exec, line);
	return (g_exit_ret);
}
