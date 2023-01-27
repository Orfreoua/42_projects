/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 02:23:40 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/30 20:41:58 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

t_data	*add_l_arg(void)
{
	t_data	*slot;

	slot = malloc(1 * sizeof(t_data));
	if (slot == NULL)
		return (NULL);
	slot->suiv = NULL;
	slot->str = NULL;
	slot->follow = 0;
	slot->token = DEFAULT;
	return (slot);
}

void	del_l_arg(t_data *data)
{
	if (data->str != NULL)
		free(data->str);
	free(data);
}

void	clean_list(t_data *slot)
{
	t_data	*save;
	int		n_vid;

	save = NULL;
	while (slot != NULL)
	{
		n_vid = 0;
		while (slot->suiv != NULL && slot->suiv->token == 0 && n_vid == 0)
		{
			if (slot->suiv->str == NULL
				|| slot->suiv->str[0] == '\0')
			{
				save = slot->suiv->suiv;
				del_l_arg(slot->suiv);
				slot->suiv = save;
			}
			else
			{
				n_vid = 1;
			}
		}
		slot = slot->suiv;
	}
}
