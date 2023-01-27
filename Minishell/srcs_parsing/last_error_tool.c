/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_error_tool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 02:10:29 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/30 20:41:58 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

int	ft_cmp_token(t_data *data)
{
	if (data && data->token > ARG && data->token < S_QUOTE)
		return (FOUND);
	return (N_FOUND);
}

void	ft_arg_cmd_token(t_data *slot, int *cmd)
{
	if ((*cmd) == 0)
	{
		slot->token = CMD;
		(*cmd) = 1;
	}
	else
		slot->token = ARG;
}

void	ft_token(t_data *data)
{
	int		cmd;
	t_data	*slot;

	slot = data;
	cmd = 0;
	while (slot != NULL)
	{
		if (slot->token == DEFAULT || slot->token == S_QUOTE
			|| slot->token == D_QUOTE)
			ft_arg_cmd_token(slot, &cmd);
		else if (slot->token == PIPE)
			cmd = 0;
		else if (slot->token > PIPE && slot->token < D_L_REDIR)
			slot->suiv->token = ARG_FILE;
		else if (slot->token == D_L_REDIR)
			slot->suiv->token = EX_CODE;
		slot = slot->suiv;
	}
}
