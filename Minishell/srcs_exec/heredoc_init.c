/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:56:19 by orfreoua          #+#    #+#             */
/*   Updated: 2022/12/09 14:56:23 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*gen_name(t_exec *exec, int i)
{
	char	*nb;

	nb = ft_itoa(i);
	if (!nb)
	{
		print_error("malloc fail, gen_name()");
		return (NULL);
	}
	exec->hd.tab_of_name_file[i] = ft_strjoin("hold/temp", nb, 0);
	if (!exec->hd.tab_of_name_file[i])
		print_error("malloc failed 1");
	free(nb);
	return (exec->hd.tab_of_name_file[i]);
}

int	init_file_heredoc(t_exec *exec)
{
	exec->hd.tab_of_name_file = malloc(sizeof(char *)
			* (exec->hd.nb + 1));
	if (!exec->hd.tab_of_name_file)
	{
		free_tab(exec->hd.tab_exit_code);
		return (print_error("(l:22) malloc failed 3"));
	}
	exec->hd.tab_fd = malloc(sizeof(int) * exec->hd.nb);
	if (!exec->hd.tab_fd)
	{
		free(exec->hd.tab_of_name_file);
		free_tab(exec->hd.tab_exit_code);
		return (print_error("(l:29) malloc failed 4"));
	}
	return (OK);
}

int	init_tab_exitcode(t_data *data, t_exec *exec)
{
	t_data	*slot;
	int		i;

	slot = data;
	exec->hd.tab_exit_code = malloc(sizeof(char *) * (exec->hd.nb + 1));
	if (!exec->hd.tab_exit_code)
		return (print_error("(l:42) malloc failed 1"));
	i = 0;
	while (slot != NULL)
	{
		if (slot->token == D_L_REDIR)
		{
			exec->hd.tab_exit_code[i] = ft_strdup(slot->suiv->str);
			if (!exec->hd.tab_exit_code[i])
			{
				free_tab_error(exec->hd.tab_exit_code, i);
				return (print_error("(l:52) malloc failed 2"));
			}
			i++;
		}
		slot = slot->suiv;
	}
	return (OK);
}

int	count_nb_heredoc(t_data *data)
{
	t_data	*slot;
	int		i;

	slot = data;
	i = 0;
	while (slot != NULL)
	{
		if (slot->token == D_L_REDIR)
			i++;
		slot = slot->suiv;
	}
	return (i);
}

int	load_heredoc(t_data *data, t_exec *exec)
{
	int	i;

	exec->hd.nb = count_nb_heredoc(data);
	if (!exec->hd.nb)
		return (OK);
	exec->hd.tab_exit_code = NULL;
	if (init_tab_exitcode(data, exec) == ERROR)
		return (print_error("init_heredoc.c"));
	if (init_file_heredoc(exec) == ERROR)
	{
		free_tab(exec->hd.tab_exit_code);
		return (print_error("init_heredoc.c"));
	}
	i = 0;
	while (g_exit_ret != 424242 && i < exec->hd.nb)
		heredoc(exec, i++);
	return (OK);
}
