/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:57:28 by orfreoua          #+#    #+#             */
/*   Updated: 2022/12/09 14:57:31 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

/*int	is_cat_cmd(t_data *data)
{
	t_data	*slot;

	slot = data;
	while (slot && slot->token != PIPE)
	{
		if (!ft_strncmp(slot->str, "cat", 3))
			return (1);
		slot = slot->suiv;
	}
	return (0);
}*/

int	get_cmd(t_data	*slot, t_exec *exec)
{
	while (slot && slot->token != PIPE)
	{
		if (is_redir(slot))
			slot = slot->suiv;
		else
		{
			if (ft_strlen(exec->pipe.cmd))
				exec->pipe.cmd = ft_strjoin(exec->pipe.cmd, slot->str, 1);
			else
				exec->pipe.cmd = ft_strdup(slot->str);
			if (!exec->pipe.cmd)
				return (print_error("malloc 1, get_cmd()"));
			if (slot->suiv)
				exec->pipe.cmd = ft_strjoin(exec->pipe.cmd, " ", 1);
			if (!exec->pipe.cmd)
				return (print_error("malloc 2, get_cmd()"));
		}
		if (slot)
			slot = slot->suiv;
	}
	return (OK);
}

int	fill_and_pass_redir(t_data *data, t_exec *exec)
{
	t_data	*slot;
	int		size;

	slot = data;
	size = 0;
	while (slot && slot->token != PIPE)
	{
		if (is_redir(slot))
			slot = slot->suiv;
		else
		{
			exec->pipe.cmd_splited[size] = ft_strdup(slot->str);
			if (!exec->pipe.cmd_splited[size])
				return (ERROR);
			size++;
		}
		if (slot)
			slot = slot->suiv;
	}
	exec->pipe.cmd_splited[size] = NULL;
	return (OK);
}

int	get_cmd_splited(t_data *data, t_exec *exec)
{
	t_data	*slot;
	int		size;

	size = 0;
	slot = data;
	while (slot && slot->token != PIPE)
	{
		if (is_redir(slot))
			slot = slot->suiv;
		else
			size++;
		if (slot)
			slot = slot->suiv;
	}
	exec->pipe.cmd_splited = malloc(sizeof(char *) * (size + 1));
	if (!exec->pipe.cmd_splited)
		return (ERROR);
	fill_and_pass_redir(data, exec);
	return (OK);
}

int	load_struct_pipe(t_data	*data, t_exec *exec, int cpt_pipe)
{
	t_data	*slot;

	slot = pass_hold_pipe(data, cpt_pipe);
	if (get_cmd(slot, exec) == ERROR)
		return (ERROR);
	if (get_cmd_splited(slot, exec) == ERROR)
		return (ERROR);
	if (!exec->pipe.cmd_splited)
		return (print_error("malloc, split()"));
	if (ft_strlen(exec->pipe.cmd_splited[0]))
	{
		if (find_index(exec->pipe.cmd_splited[0], '/') > -1)
		{
			exec->pipe.path_cmd = ft_strdup(exec->pipe.cmd_splited[0]);
			if (!exec->pipe.path_cmd)
				return (print_error("malloc, ft_strdup()"));
		}
		else
			exec->pipe.path_cmd = getpath(exec->pipe.cmd_splited[0],
					exec->env);
	}
	return (OK);
}
