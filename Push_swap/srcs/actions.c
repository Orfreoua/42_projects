/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:59:19 by orfreoua          #+#    #+#             */
/*   Updated: 2022/03/10 17:59:21 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	offset_right(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->nb)
	{
		stack->tab[i - 1] = stack->tab[i];
		i++;
	}	
}

void	push_a(t_data *data)
{
	int	i;

	if (data->a.nb == 0)
		data->a.tab[0] = data->b.tab[0];
	else
	{
		i = 0;
		while (data->a.nb - i)
		{
			data->a.tab[data->a.nb - i] = data->a.tab[data->a.nb - (i + 1)];
			i++;
		}
		data->a.tab[0] = data->b.tab[0];
	}
	data->a.nb++;
	offset_right(&data->b);
	data->b.nb--;
	data->cpt_actions++;
	ft_putndl_fd("pa", 1);
}

void	push_b(t_data *data)
{
	int	i;

	if (data->b.nb == 0)
		data->b.tab[0] = data->a.tab[0];
	else
	{
		i = 0;
		while (data->b.nb - i)
		{
			data->b.tab[data->b.nb - i] = data->b.tab[data->b.nb - (i + 1)];
			i++;
		}
		data->b.tab[0] = data->a.tab[0];
	}
	data->b.nb++;
	offset_right(&data->a);
	data->a.nb--;
	data->cpt_actions++;
	ft_putndl_fd("pb", 1);
}

void	swap(t_data *data, char c)
{
	int	swap;

	if (c == 'a' || c == 's')
	{
		if (data->a.tab && data->a.tab[0] && data->a.tab[1])
		{
			swap = data->a.tab[0];
			data->a.tab[0] = data->a.tab[1];
			data->a.tab[1] = swap;
			if (c == 'a')
				ft_putndl_fd("sa", 1);
		}
	}
	if (c == 'b' || c == 's')
	{
		if (data->b.tab && data->b.tab[0] && data->b.tab[1])
		{
			swap = data->b.tab[0];
			data->b.tab[0] = data->b.tab[1];
			data->b.tab[1] = swap;
			if (c == 'b')
				ft_putndl_fd("sb", 1);
		}
	}
	data->cpt_actions++;
}
