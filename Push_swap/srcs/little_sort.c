/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:18:57 by orfreoua          #+#    #+#             */
/*   Updated: 2022/03/10 20:18:58 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(int *s, t_data *data)
{
	if (stack_is_sorted(&data->a))
		return ;
	if ((s[0] > s[1]) && (s[0] < s[2]))
		swap(data, 'a');
	else if ((s[0] > s[1]) && (s[1] > s[2]))
	{
		swap(data, 'a');
		reverse_rotate_a(data, 'a');
	}
	else if ((s[0] > s[1]) && (s[1] < s[2]))
		rotate_a(data, 'a');
	else if ((s[0] < s[1]) && (s[0] < s[2]))
	{
		swap(data, 'a');
		rotate_a(data, 'a');
	}
	else if ((s[0] < s[1]) && (s[0] > s[2]))
		reverse_rotate_a(data, 'a');
}

void	optimisation(t_data *data)
{
	if (data->a.tab[0] > data->a.tab[1]
		&& data->a.tab[0] < data->a.tab[2]
		&& data->a.tab[2] < data->a.tab[3]
		&& data->a.tab[3] < data->a.tab[4])
		swap(data, 'a');
}

int	special_cast(int *s)
{
	if ((s[0] > s[2] && s[2] > s[4]
			&& s[4] > s[3] && s[3] > s[1])
		|| (s[1] < s[3] && s[3] < s[2]
			&& s[2] < s[0] && s[0] < s[4]))
		return (1);
	return (0);
}

void	sort_five(t_data *data)
{
	int	pos_smallest;

	if ((data->a.nb == 5) && special_cast(data->a.tab))
		rotate_a(data, 'a');
	while (data->a.nb != 3)
	{
		pos_smallest = find_pos_smallest(&data->a);
		while (pos_smallest != 0)
		{
			if (pos_smallest >= 3)
				reverse_rotate_a(data, 'a');
			else
				rotate_a(data, 'a');
			pos_smallest = find_pos_smallest(&data->a);
		}
		push_b(data);
	}
	sort_three(data->a.tab, data);
	while (data->b.nb)
		push_a(data);
}
