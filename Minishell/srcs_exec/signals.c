/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:00:53 by orfreoua          #+#    #+#             */
/*   Updated: 2022/11/13 23:00:57 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	sigint_heredoc(int sig_num)
{
	if (sig_num == SIGINT)
	{
		write(1, "\n", 1);
		close(STDIN_FILENO);
		g_exit_ret = 424242;
	}
}

void	redisplay_prompt(void)
{
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	ft_putstr_fd(STDERR_FILENO, "  \b\b");
}

static void	new_line(int sig_num)
{
	if (sig_num == SIGINT)
	{
		write(1, "\n", 1);
		redisplay_prompt();
		g_exit_ret = sig_num + 128;
	}
}

void	signal_catching_mode(int mode)
{
	if (mode == INTERACTIVE)
	{
		signal(SIGINT, new_line);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mode == PARENT_PROCESS)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (mode == CHILD_PROCESS)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
	else if (mode == HEREDOC)
	{
		signal(SIGINT, sigint_heredoc);
		signal(SIGQUIT, SIG_IGN);
	}
}
