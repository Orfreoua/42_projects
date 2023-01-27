/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:55:58 by orfreoua          #+#    #+#             */
/*   Updated: 2022/12/09 14:56:02 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	print_error(char *s)
{
	ft_putstr_fd(STDERR_FILENO, "ERROR: ");
	ft_putstr_fd(STDERR_FILENO, s);
	write(STDERR_FILENO, "\n", 1);
	g_exit_ret = 127;
	return (ERROR);
}

void	print_error_heredoc(t_exec *exec, int pos)
{
	ft_putstr_fd(STDERR_FILENO, "minishell : warning: here-document at line ");
	ft_putnbr_fd(exec->nb_execution, STDERR_FILENO);
	ft_putstr_fd(STDERR_FILENO, " delimited by end-of-file (wanted `");
	ft_putstr_fd(STDERR_FILENO, exec->hd.tab_exit_code[pos]);
	ft_putstr_fd(STDERR_FILENO, "')\n");
}

int	print_error_cmd(t_exec *exec)
{
	ft_putstr_fd(STDERR_FILENO, exec->pipe.path_cmd);
	ft_putstr_fd(STDERR_FILENO, ": command not found\n");
	g_exit_ret = 127;
	return (ERROR);
}

int	error_export(char *s)
{
	ft_putstr_fd(STDERR_FILENO, "minishell: export: `");
	ft_putstr_fd(STDERR_FILENO, s);
	ft_putstr_fd(STDERR_FILENO, "': not a valid identifier\n");
	return (0);
}
