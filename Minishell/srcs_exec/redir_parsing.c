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

int	is_redir_in(t_data *data, t_exec *exec)
{
	if (data->token == D_L_REDIR || data->token == S_L_REDIR)
	{
		if (data->token == D_L_REDIR)
			exec->hd.cpt_file++;
		return (1);
	}
	return (0);
}

int	redir_in(t_data *data, t_exec *exec)
{
	t_data	*tmp;

	tmp = NULL;
	while (data && data->token != PIPE)
	{
		if (is_redir_in(data, exec))
			tmp = data;
		data = data->suiv;
	}
	if (tmp)
	{
		if (tmp->token == D_L_REDIR)
		{
			if (do_redir(tmp->token,
					exec->hd.tab_of_name_file[exec->hd.cpt_file], exec)
				== ERROR)
				return (ERROR);
			return (OK);
		}
		if (do_redir(tmp->token, tmp->suiv->str, exec) == ERROR)
			return (ERROR);
	}
	return (OK);
}

int	redir_out(t_data *data, t_exec *exec)
{
	t_data	*tmp;

	tmp = NULL;
	while (data && data->token != PIPE)
	{
		if (data->token == D_R_REDIR || data->token == S_R_REDIR)
			tmp = data;
		data = data->suiv;
	}
	if (tmp)
	{
		if (do_redir(tmp->token, tmp->suiv->str, exec) == ERROR)
			return (ERROR);
	}
	return (OK);
}

int	good_pos_hd(t_data *data, int cpt_pipe)
{
	t_data	*slot;
	int		i;
	int		pos_hd;

	pos_hd = 0;
	i = 0;
	slot = data;
	while (slot && i < cpt_pipe)
	{
		if (slot->token == PIPE)
			i++;
		if (slot->token == D_L_REDIR)
			pos_hd++;
		slot = slot->suiv;
	}
	return (pos_hd - 1);
}

int	redir(t_data *data, t_exec *exec, int cpt_pipe)
{
	t_data	*slot;
	t_data	*slot2;

	slot = data;
	slot2 = data;
	exec->hd.cpt_file = good_pos_hd(data, cpt_pipe);
	slot = pass_hold_pipe(data, cpt_pipe);
	slot2 = pass_hold_pipe(data, cpt_pipe);
	if (redir_in(slot, exec) == ERROR)
		return (ERROR);
	dup2(exec->pipe.prev, STDIN_FILENO);
	if (redir_out(slot2, exec) == ERROR)
		return (ERROR);
	dup2(exec->pipe.fd_pipe[1], STDOUT_FILENO);
	return (OK);
}
