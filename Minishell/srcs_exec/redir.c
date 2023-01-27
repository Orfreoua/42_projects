/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:56:52 by orfreoua          #+#    #+#             */
/*   Updated: 2022/12/09 14:56:55 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	is_redir(t_data *slot)
{
	if (slot->token == S_L_REDIR || slot->token == D_L_REDIR
		|| slot->token == S_R_REDIR || slot->token == D_R_REDIR)
		return (1);
	return (0);
}

int	error_fd_dosent_exist(char *filename)
{
	ft_putstr_fd(2, "minishell : ");
	ft_putstr_fd(2, filename);
	ft_putstr_fd(2, " : No such file or directory\n");
	g_exit_ret = 1;
	exit(1);
}

int	openfile(char *filename, int mode)
{
	int	fd;

	if (!mode)
	{
		if (access(filename, F_OK))
			return (error_fd_dosent_exist(filename));
		fd = open(filename, O_RDONLY);
		if (fd == -1)
		{
			close(fd);
			exit(1);
		}
		return (fd);
	}
	else if (mode == 1)
	{
		fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (!access(filename, F_OK) && fd == -1)
			exit(1);
		return (fd);
	}
	fd = open(filename, O_CREAT | O_WRONLY | O_APPEND, 0744);
	if (access(filename, F_OK) || fd == -1)
		exit(1);
	return (fd);
}

int	do_redir(int redir, char *str, t_exec *exec)
{
	if (redir == S_R_REDIR)
		exec->pipe.fd_pipe[1] = openfile(str, 1);
	else if (redir == D_R_REDIR)
		exec->pipe.fd_pipe[1] = openfile(str, 2);
	else if (redir == S_L_REDIR)
		exec->pipe.prev = openfile(str, 0);
	else if (redir == D_L_REDIR)
		exec->pipe.prev = openfile(str, 0);
	if (!exec->pipe.fd_pipe[0] || !exec->pipe.fd_pipe[1])
		return (ERROR);
	return (OK);
}
