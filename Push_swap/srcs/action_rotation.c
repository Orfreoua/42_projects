/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:43:50 by orfreoua          #+#    #+#             */
/*   Updated: 2022/03/11 16:43:51 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_data *data, char c)
{
	int	swap;
	int	i;

	i = 1;
	swap = data->a.tab[0];
	while (i < data->a.nb)
	{
		data->a.tab[i - 1] = data->a.tab[i];
		i++;
	}
	data->a.tab[i - 1] = swap;
	if (c == 'a')
	{
		ft_putndl_fd("ra", 1);
		data->cpt_actions++;
	}
}

void	rotate_b(t_data *data, char c)
{
	int	swap;
	int	i;

	i = 1;
	swap = data->b.tab[0];
	while (i < data->b.nb)
	{
		data->b.tab[i - 1] = data->b.tab[i];
		i++;
	}
	data->b.tab[i - 1] = swap;
	if (c == 'b')
	{
		ft_putndl_fd("rb", 1);
		data->cpt_actions++;
	}
}

void	reverse_rotate_a(t_data *data, char c)
{
	int	swap;
	int	i;

	swap = data->a.tab[data->a.nb - 1];
	data->a.tab[data->a.nb - 1] = data->a.tab[0];
	i = data->a.nb - 1;
	while (i > 0)
	{
		data->a.tab[i] = data->a.tab[i - 1];
		i--;
	}
	data->a.tab[0] = swap;
	if (c == 'a')
	{
		ft_putndl_fd("rra", 1);
		data->cpt_actions++;
	}
}

void	reverse_rotate_b(t_data *data, char c)
{
	int	swap;
	int	i;

	swap = data->b.tab[data->b.nb - 1];
	data->b.tab[data->b.nb - 1] = data->b.tab[0];
	i = data->b.nb - 1;
	while (i > 0)
	{
		data->b.tab[i] = data->b.tab[i - 1];
		i--;
	}
	data->b.tab[0] = swap;
	if (c == 'b')
	{
		ft_putndl_fd("rrb", 1);
		data->cpt_actions++;
	}
}
