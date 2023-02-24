/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:28:24 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/24 23:53:47 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	draw_mmplayer(t_data *data)
{
	double	x;
	double	y;

	x = data->minimap.pos_player.x;
	y = data->minimap.pos_player.y;
	draw_full_circle(data, x, y, 3);
}

void	display_mmrays(t_data *data)
{
	t_point	p1;
	int		cpt;
	int		nb_rays;

	p1.x = data->minimap.pos_player.x;
	p1.y = data->minimap.pos_player.y;
	cpt = 0;
	nb_rays = (int)RESO_X;
	while (cpt < nb_rays)
	{
		if (cpt % (RESO_X / 10) == 0)
			draw_line(data, p1, data->rc.rays[cpt], WHEAT_BEIGE);
		cpt++;
	}
}

void	cell(t_data *data, int x, int y, unsigned int color)
{
	t_point	c;
	double	r;
	int		i;
	int		j;

	c.x = x * data->minimap.cell.width + data->minimap.cell.width
		/ 2 + data->minimap.mmoffset.width;
	c.y = y * data->minimap.cell.height + data->minimap.cell.height
		/ 2 + data->minimap.mmoffset.height;
	r = data->minimap.cell.width / 2 - 1;
	i = c.x - r;
	while (i <= c.x + r)
	{
		j = c.y - r;
		while (j <= c.y + r)
		{
			if ((x == 0 && y == 0) || (x == 0
					&& y == data->file.grid.height - 1)
				|| (x == data->file.grid.width - 1 && y == 0)
				|| (x == data->file.grid.width - 1
					&& y == data->file.grid.height - 1))
			{
				if ((i - c.x) * (i - c.x) + (j - c.y) * (j - c.y) <= r * r)
					draw_point(data, i, j, (color * 2));
			}
			else
				draw_point(data, i, j, color);
			j++;
		}
		i++;
	}
}

void	display_minimap(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->file.map[y])
	{
		x = 0;
		while (data->file.map[y][x])
		{
			if (data->file.map[y][x] == '1')
				cell(data, x, y, BABY_BLUE);
			else if (data->file.map[y][x] == '0' || data->file.map[y][x] == 'N')
				cell(data, x, y, LAVENDER_MIST);
			x++;
		}
		y++;
	}
	display_mmrays(data);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.ptr_win,
		data->mlx.screen.ptr, 0, 0);
	draw_mmplayer(data);
}

void	mini_map_init(t_data *data, t_minimap *minimap)
{
	minimap->mmoffset.width = RESO_X * 0.76;
	minimap->mmoffset.height = (RESO_Y * 0.76);
	minimap->reso.width = RESO_X * MMRATIO_X;
	minimap->reso.height = RESO_Y * MMRATIO_Y;
	minimap->cell.height = minimap->reso.height / data->file.grid.height;
	minimap->cell.width = minimap->reso.width / data->file.grid.width;
	minimap->pos_player.y = (data->file.pos_player.y * minimap->cell.height)
		+ (minimap->cell.height / 2) + minimap->mmoffset.height;
	minimap->pos_player.x = (data->file.pos_player.x * minimap->cell.width)
		+ (minimap->cell.width / 2) + minimap->mmoffset.width;
	minimap->center.x = minimap->reso.width / 2;
	minimap->center.y = minimap->reso.height / 2;
	minimap->radius = 100;
}
