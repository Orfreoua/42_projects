/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:39:34 by orfreoua          #+#    #+#             */
/*   Updated: 2022/03/18 14:40:22 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	multiple_rotate(t_data *data, int repetition, char index)
{
	if (index == 'a')
	{
		while (repetition)
		{
			rotate_a(data, 'a');
			repetition--;
		}
	}
	else
	{
		while (repetition)
		{
			rotate_a(data, 'b');
			repetition--;
		}
	}
}

void	multiple_reverse_rotate(t_data *data, int repetition, char index)
{
	if (index == 'a')
	{
		while (repetition)
		{
			reverse_rotate_a(data, 'a');
			repetition--;
		}
	}
	else
	{
		while (repetition)
		{
			reverse_rotate_a(data, 'b');
			repetition--;
		}
	}
}
