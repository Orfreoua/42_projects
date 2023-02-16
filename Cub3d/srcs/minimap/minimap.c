/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:28:24 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/16 21:58:37 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	draw_mmplayer(t_data *data)
{
	double x;
	double y;

	x = data->minimap.pos_player.x;
	y = data->minimap.pos_player.y;
	printf("x : %f\n", x);
	printf("y : %f\n", y);
	draw_point(data, x, y, 0xBD131F);
}

void	display_mmrays(t_data *data)
{
	t_point p1;
	
	p1.x = data->file.pos_player.x + MMOFFSET_X;
	p1.y = data->file.pos_player.y + MMOFFSET_Y;

	int cpt = 0;
	int nb_rays = (int)RESO_X;

	while (cpt < nb_rays)
	{
		//Draw ray
		draw_line(data, p1, data->rc.rays[cpt], 555555);
		//draw_pointbypoint(data, data->rays[cpt], start_color);
		cpt++;
	}
}

void	cell(t_data *data, int x, int y, unsigned int color)
{
	double	a;
	double	b;
	double	cpy_a;
	double	cpy_b;

	a =  (y * data->minimap.cell.height) + MMOFFSET_Y;
	b = (x * data->minimap.cell.width) + MMOFFSET_X;
	cpy_a = a + data->minimap.cell.height;
	cpy_b = b + data->minimap.cell.width;
	while (a < cpy_a)
	{
		b = (x * data->minimap.cell.width) + MMOFFSET_X;
		while (b < cpy_b)
		{
			if (a == (y * data->minimap.cell.height) + MMOFFSET_Y
			|| b == (x * data->minimap.cell.width) + MMOFFSET_X
			|| a == cpy_a - 1 || b == cpy_b - 1)
				draw_point(data, b, a, 0);
			else
				draw_point(data, b, a, color);
			b++;
		}
		a++;
	}
}

void	display_minimap(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (data->file.map[y])
	{
		x = 0;
		printf("%s\n", data->file.map[y]);
		while (data->file.map[y][x])
		{
			if (data->file.map[y][x] == '1')
				cell(data, x, y, 7777777); // random color
			else if (data->file.map[y][x] == '0' || data->file.map[y][x] == 'N')
				cell(data, x, y, 0xfffacd); // random color
			x++;
		}
		y++;
	}
	display_mmrays(data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.ptr_win, data->mlx.screen.ptr, 0, 0);
	draw_mmplayer(data);
}

void	mini_map_init(t_data *data, t_minimap *minimap)
{
	minimap->reso.width = RESO_X * MMRATIO_X;
	minimap->reso.height = RESO_Y * MMRATIO_Y;
	minimap->cell.height = minimap->reso.height / data->file.grid.height;
	minimap->cell.width = minimap->reso.width / data->file.grid.width;
	minimap->pos_player.y = (data->file.pos_player.y * minimap->cell.height)
		+ (minimap->cell.height / 2) + MMOFFSET_Y;
	minimap->pos_player.x = (data->file.pos_player.x * minimap->cell.width)
		+ (minimap->cell.width / 2) + MMOFFSET_X;
}

