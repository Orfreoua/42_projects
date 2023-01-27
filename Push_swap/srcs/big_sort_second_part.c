/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_second_part.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:01:46 by orfreoua          #+#    #+#             */
/*   Updated: 2022/03/14 11:01:47 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_pos_smallest(t_stack *stack)
{
	int	smallest;
	int	pos_smallest;
	int	cpt;

	smallest = stack->tab[0];
	pos_smallest = 0;
	cpt = 0;
	while (cpt < stack->nb)
	{
		if (smallest > stack->tab[cpt])
		{
			smallest = stack->tab[cpt];
			pos_smallest = cpt;
		}
		cpt++;
	}
	return (pos_smallest);
}

int	find_pos_biggest(t_stack *stack)
{
	int	biggest;
	int	pos_biggest;
	int	cpt;

	biggest = stack->tab[0];
	pos_biggest = 0;
	cpt = 0;
	while (cpt < stack->nb)
	{
		if (biggest < stack->tab[cpt])
		{
			biggest = stack->tab[cpt];
			pos_biggest = cpt;
		}
		cpt++;
	}
	return (pos_biggest);
}

int	nb_moves(t_stack *stack, int starting_pos)
{
	if (starting_pos < (stack->nb / 2))
		return (starting_pos);
	else
		return (stack->nb - starting_pos);
}

void	put_on_the_top(t_data *data, int repetition, int x)
{
	while (repetition)
	{
		if (x == 0)
			reverse_rotate_b(data, 'b');
		else
			rotate_b(data, 'b');
		repetition--;
	}
}

void	repush_on_a(t_data *data)
{
	data->x.pos_smallest = find_pos_smallest(&data->b);
	data->x.hold_smallest = data->b.tab[data->x.pos_smallest];
	data->x.pos_biggest = find_pos_biggest(&data->b);
	data->x.nb_moves_biggest = nb_moves(&data->b, data->x.pos_biggest);
	data->x.nb_moves_smallest = nb_moves(&data->b, data->x.pos_smallest);
	if (data->x.nb_moves_biggest < data->x.nb_moves_smallest)
	{
		if (data->x.pos_biggest > (data->b.nb / 2))
			put_on_the_top(data, data->x.nb_moves_biggest, 0);
		else
			put_on_the_top(data, data->x.nb_moves_biggest, 1);
	}
	else
	{
		if (data->x.pos_smallest > (data->b.nb / 2))
			put_on_the_top(data, data->x.nb_moves_smallest, 0);
		else
			put_on_the_top(data, data->x.nb_moves_smallest, 1);
	}
	push_a(data);
	if (data->a.tab[0] == data->x.hold_smallest)
		rotate_a(data, 'a');
}
