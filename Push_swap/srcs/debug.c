/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:06:51 by orfreoua          #+#    #+#             */
/*   Updated: 2022/03/10 18:06:53 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->nb - 1)
	{
		if (stack->tab[i] > stack->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	print_stack(int *stack, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr_fd(stack[i], 1);
		write(1, " | ", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	selectif_sort(t_stack *stack)
{
	int	i;
	int	swp;

	i = 0;
	while (i < stack->nb - 1)
	{
		if (stack->tab[i] > stack->tab[i + 1])
		{
			swp = stack->tab[i];
			stack->tab[i] = stack->tab[i + 1];
			stack->tab[i + 1] = swp;
			i = -1;
		}
		i++;
	}
}

void	positif_vallue(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->a.nb)
	{
		j = 0;
		while (data->a.tab[i] != data->orange.tab[j])
			j++;
		data->a.tab[i] = j;
		i++;
	}
}

int	find_bigger_nb(t_stack *data)
{
	int	i;
	int	bigger_nb;

	i = 0;
	bigger_nb = data->tab[0];
	while (i < data->nb)
	{
		if (bigger_nb < data->tab[i])
			bigger_nb = data->tab[i];
		i++;
	}
	return (bigger_nb);
}
