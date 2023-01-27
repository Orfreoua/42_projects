/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:19:15 by orfreoua          #+#    #+#             */
/*   Updated: 2022/03/10 20:19:16 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	convert_with_positif_vallue(t_data *data)
{
	data->orange.tab = malloc(sizeof(int) * data->a.nb);
	if (!data->orange.tab)
		free_all(data);
	copy_stack(data->orange.tab, &data->a);
	data->orange.nb = data->a.nb;
	selectif_sort(&data->orange);
	positif_vallue(data);
	free_tab_integer(data->orange.tab);
	data->orange.nb = 0;
}

int	left_to_right(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->a.nb)
	{
		if (data->a.tab[i] < data->chunk.right)
		{
			if (data->a.tab[i + 1] < data->a.tab[i])
				i++;
			break ;
		}
		i++;
	}
	return (i);
}

int	right_to_left(t_data *data)
{
	int	i;

	i = 1;
	while (data->a.nb - i > 0)
	{
		if (data->a.tab[data->a.nb - i] < data->chunk.right)
		{
			if (data->a.tab[data->a.nb - (i + 1)] < data->a.tab[data->a.nb - i])
				i++;
			break ;
		}
		i++;
	}
	return (i);
}

void	send_chunk_by_chunk(t_data *data)
{
	int	left;
	int	right;

	if (data->chunk.left == data->chunk.right)
		data->chunk.right += data->chunk.chunki;
	left = left_to_right(data);
	right = right_to_left(data);
	if (data->a.tab[right] < data->a.tab[left] && right <= left + 1)
		multiple_reverse_rotate(data, right, 'a');
	else if (data->a.tab[left] < data->a.tab[right] && left <= right + 1)
		multiple_rotate(data, left, 'a');
	else if (left < right)
		multiple_rotate(data, left, 'a');
	else
		multiple_reverse_rotate(data, right, 'a');
	data->chunk.left++;
	push_b(data);
}

void	big_sort(t_data *data)
{
	convert_with_positif_vallue(data);
	while (data->a.nb)
		send_chunk_by_chunk(data);
	while (data->b.nb)
		repush_on_a(data);
	while (data->a.tab[0] != 0)
		rotate_a(data, 'a');
}
