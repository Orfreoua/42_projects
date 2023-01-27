/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:19:05 by orfreoua          #+#    #+#             */
/*   Updated: 2022/03/10 20:19:07 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error(int return_value, char *msg, int fd)
{
	ft_putndl_fd(msg, fd);
	return (return_value);
}

void	init_data(t_data *data)
{
	data->a.nb = 0;
	data->b.nb = 0;
	data->orange.nb = 0;
	data->cpt_actions = 0;
	if (data->a.nb < 200)
		data->chunk.chunki = 20;
	else
		data->chunk.chunki = 40;
	data->chunk.left = 0;
	data->chunk.right = data->chunk.chunki;
}

void	mallo_b(t_data *data)
{
	data->b.tab = malloc(sizeof(int) * data->a.nb);
	if (!data->b.tab)
	{
		free(data->a.tab);
		ft_putndl_fd("Malloc failed (3)", 1);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (0);
	init_data(&data);
	if (!load_data(&data, argc, argv))
		return (1);
	mallo_b(&data);
	if (stack_is_sorted(&data.a))
	{
		free_all(&data);
		return (0);
	}
	if (data.a.nb == 2)
		swap(&data, 'a');
	else if (data.a.nb == 3)
		sort_three(data.a.tab, &data);
	else if (data.a.nb <= 5)
		sort_five(&data);
	else
		big_sort(&data);
	free_all(&data);
	return (0);
}
