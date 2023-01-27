/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:07:20 by orfreoua          #+#    #+#             */
/*   Updated: 2022/12/22 21:07:24 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*add_contents(char *contents, char *s)
{
	contents = ft_strjoin(contents, s, 1);
	if (!contents)
	{
		print_error("malloc failed 2");
		return (NULL);
	}
	contents = ft_strjoin(contents, "\n", 1);
	if (!contents)
		print_error("malloc failed 3");
	return (contents);
}

void	end_heredoc(char **contents, t_exec *exec, char **s, int *i)
{
	write(exec->hd.tab_fd[*i], *contents, ft_strlen(*contents));
	if (!s && g_exit_ret != 424242)
		print_error_heredoc(exec, *i);
	if (*s)
		free(*s);
}

int	boucle(char **contents, int *i, t_exec *exec)
{
	char	*s;

	s = readline("> ");
	if (!s || !strcmp(s, exec->hd.tab_exit_code[*i]))
		return (end_heredoc(contents, exec, &s, i), 2);
	else
	{
		s = ft_heredoc_expand(s, exec->env);
		if (!s)
		{
			free_string(*contents);
			return (print_error("2 heredoc()"));
		}
		*contents = add_contents(*contents, s);
		if (!*contents)
		{
			free(s);
			return (print_error("3 heredoc()"));
		}
	}
	if (s)
		free_string(s);
	return (3);
}

int	to_fill_heredoc(int i, t_exec *exec)
{
	int		start;
	char	*contents;

	contents = malloc(sizeof(char) * 1);
	if (!contents)
		return (print_error("heredoc()"));
	contents[0] = 0;
	start = 0;
	while (!start || strcmp(contents, exec->hd.tab_exit_code[i]))
	{
		start = boucle(&contents, &i, exec);
		if (start == 2)
			break ;
		else if (start == ERROR)
			return (ERROR);
	}
	free_string(contents);
	return (OK);
}

int	heredoc(t_exec *exec, int i)
{
	int	hold_fd;

	hold_fd = dup(STDIN_FILENO);
	signal_catching_mode(HEREDOC);
	exec->hd.tab_fd[i] = create_file(gen_name(exec, i), exec);
	if (exec->hd.tab_fd[i] == ERROR)
		return (ERROR);
	if (to_fill_heredoc(i, exec) == ERROR)
		return (ERROR);
	signal_catching_mode(INTERACTIVE);
	if (g_exit_ret == 424242)
		free_heredoc(exec);
	dup2(hold_fd, STDIN_FILENO);
	close(hold_fd);
	exec->hd.cpt++;
	return (OK);
}
