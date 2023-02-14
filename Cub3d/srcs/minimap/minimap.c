/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:28:24 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/14 20:41:25 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	cell(t_data *data, int x, int y, unsigned int color)
{
	double	a;
	double	b;
	double	cpy_a;
	double	cpy_b;

	a =  y * data->minimap.cell.height;
	b = x * data->minimap.cell.width;
	cpy_a = a + data->minimap.cell.height;
	cpy_b = b + data->minimap.cell.width;
	while (a < cpy_a + MMOFFSET_Y)
	{
		b = x * data->minimap.cell.width + MMOFFSET_X;
		while (b < cpy_b + MMOFFSET_X)
		{
			draw_point(data, b, a, color);
			b++;
		}
		a++;
	}
}

char **init_pour_test_une_map(void)
{
	char **map;

	map = malloc(sizeof(char *) * 5);
	map[0] = ft_strdup("1111");
	map[1] = ft_strdup("1001");
	map[2] = ft_strdup("10N1");
	map[3] = ft_strdup("1111");
	map[4] = 0;
	return (map);
}

void	display_minimap(t_data *data)
{
	data->file.map = init_pour_test_une_map();
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
			else if (data->file.map[y][x] == '0')
				cell(data, x, y, 0xfffacd); // random color
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.ptr_win, data->mlx.screen.ptr, 0, 0);
	//draw_player_pos(data);
	//draw_minimap_rays(data);
}

void	mini_map_init(t_data *data, t_minimap *minimap)
{
	data->file.grid.height = 4.0;
	data->file.grid.width = 4.0;
	minimap->reso.width = RESO_X * MMRATIO_X;
	minimap->reso.height = RESO_Y * MMRATIO_Y;
	minimap->cell.height = minimap->reso.height / data->file.grid.height;
	minimap->cell.width = minimap->reso.width / data->file.grid.width;
	printf("%f\n", minimap->cell.height);
	printf("%f\n", minimap->cell.width);
	minimap->pos_player.y = (data->file.pos_player.y * minimap->cell.height)
		+ (minimap->cell.height / 2) + MMOFFSET_Y;
	minimap->pos_player.x = (minimap->pos_player.x * minimap->cell.width)
		+ (minimap->cell.width / 2) + MMOFFSET_X;
}

