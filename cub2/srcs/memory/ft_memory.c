/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:23:00 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 19:10:17 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../cub3D.h"

void	ft_init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map.grid = NULL;
	data->arg.no = NULL;
	data->arg.so = NULL;
	data->arg.ea = NULL;
	data->arg.we = NULL;
	data->text_e.img = NULL;
	data->text_s.img = NULL;
	data->text_w.img = NULL;
	data->text_n.img = NULL;
	data->buff01.img = NULL;
	data->buff02.img = NULL;
	data->menu.index = 0;
	data->menu.ison = 0;
}

void	ft_free_grid(t_map *map)
{
	int	i;

	i = 0;
	if (map->grid)
	{
		while (map->grid[i])
		{
			if (map->grid[i])
				free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
}

void	ft_free_text(t_arg *arg)
{
	if (arg->no)
		free(arg->no);
	if (arg->ea)
		free(arg->ea);
	if (arg->so)
		free(arg->so);
	if (arg->we)
		free(arg->we);
}

void	ft_free_data(t_data *data)
{
	ft_free_grid(&data->map);
	ft_free_text(&data->arg);
	if (data->text_e.img)
		mlx_destroy_image(data->mlx, data->text_e.img);
	if (data->text_s.img)
		mlx_destroy_image(data->mlx, data->text_s.img);
	if (data->text_w.img)
		mlx_destroy_image(data->mlx, data->text_w.img);
	if (data->text_n.img)
		mlx_destroy_image(data->mlx, data->text_n.img);
	if (data->buff01.img)
		mlx_destroy_image(data->mlx, data->buff01.img);
	if (data->buff02.img)
		mlx_destroy_image(data->mlx, data->buff02.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
