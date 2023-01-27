/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:40:58 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/30 20:41:58 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

t_data	*add_pipe_token(void)
{
	t_data	*slot;

	slot = add_l_arg();
	slot->str = malloc(2 * sizeof(char));
	slot->str[0] = '|';
	slot->str[1] = '\0';
	slot->token = PIPE;
	return (slot);
}

t_data	*add_s_l_redir_token(void)
{
	t_data	*slot;

	slot = add_l_arg();
	slot->str = malloc(2 * sizeof(char));
	slot->str[0] = '<';
	slot->str[1] = '\0';
	slot->token = S_L_REDIR;
	return (slot);
}

t_data	*add_s_r_redir_token(void)
{
	t_data	*slot;

	slot = add_l_arg();
	slot->str = malloc(2 * sizeof(char));
	slot->str[0] = '>';
	slot->str[1] = '\0';
	slot->token = S_R_REDIR;
	return (slot);
}

t_data	*add_d_l_redir_token(void)
{
	t_data	*slot;

	slot = add_l_arg();
	slot->str = malloc(3 * sizeof(char));
	slot->str[0] = '<';
	slot->str[1] = '<';
	slot->str[2] = '\0';
	slot->token = D_L_REDIR;
	return (slot);
}

t_data	*add_d_r_redir_token(void)
{
	t_data	*slot;

	slot = add_l_arg();
	slot->str = malloc(3 * sizeof(char));
	slot->str[0] = '>';
	slot->str[1] = '>';
	slot->str[2] = '\0';
	slot->token = D_R_REDIR;
	return (slot);
}
