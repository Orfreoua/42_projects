/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:50:21 by orfreoua          #+#    #+#             */
/*   Updated: 2022/12/09 14:50:23 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	handle_termsig_display(int signal)
{
	if (signal == SIGINT)
		ft_putstr_fd(STDERR_FILENO, "\b\b\b\b\b\b\b\b\b\b\b\b");
	else if (signal == SIGQUIT)
		ft_putstr_fd(STDERR_FILENO, "Quit (core dumped)\n");
}

void	wait_child(void)
{
	int		status;
	int		signal;

	wait(&status);
	if (WIFEXITED(status))
		g_exit_ret = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		signal = WTERMSIG(status);
		handle_termsig_display(signal);
		g_exit_ret = signal + 128;
	}
	signal_catching_mode(INTERACTIVE);
}

void	wait_children(t_exec *exec, int nb_pipe)
{
	(void)exec;
	while (nb_pipe--)
		wait_child();
}
