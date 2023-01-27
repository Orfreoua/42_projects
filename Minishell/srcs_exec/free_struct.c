/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:03:19 by orfreoua          #+#    #+#             */
/*   Updated: 2022/12/21 18:03:22 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_pipe(t_exec *exec)
{
	free(exec->pipe.cmd);
		exec->pipe.cmd = NULL;
	free(exec->pipe.path_cmd);
		exec->pipe.path_cmd = NULL;
	free_tab(exec->pipe.cmd_splited);
}

void	free_heredoc(t_exec *exec)
{
	int	i;

	if (!exec->hd.nb)
		return ;
	i = 0;
	while (i < exec->hd.cpt_close)
	{
		close(exec->hd.tab_fd[i]);
		i++;
	}
	free(exec->hd.tab_fd);
	free_tab_error(exec->hd.tab_of_name_file, exec->hd.cpt_close);
	free_tab_error(exec->hd.tab_exit_code, exec->hd.cpt_close);
	exec->hd.nb = 0;
	exec->hd.cpt_close = 0;
}

int	free_history_end(t_exec *exec, t_data *data, int i)
{
	free_heredoc(exec);
	close_and_wait(exec, i);
	wait_children(exec, i);
	gest_error(END, data);
	return (OK);
}
