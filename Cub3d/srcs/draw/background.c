/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 05:03:38 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/21 05:21:42 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_background(t_data *data)
{
	int x;
	int y;
	int floor;
	int ceiling;

/*
0x87CEEB
Rouge (R) : 135
Vert (G) : 206
Bleu (B) : 235
La couleur de sol :

Copy code
0xC2B280
Rouge (R) : 194
Vert (G) : 178
Bleu (B) : 128
*/

	/*floor = create_trgb(data->file.floor[0], data->file.floor[1], data->file.floor[2], 0);
	ceiling = create_trgb(data->file.ceiling[0], data->file.ceiling[1], data->file.ceiling[2], 0);*/
	floor = 0xC2B280;
	ceiling = 0x87CEEB;
	y = 0;
	while (y < RESO_Y)
	{
		x = 0;
		while (x < RESO_X)
		{
			if (y < RESO_Y / 2)
				draw_point(data, x, y, ceiling);
			else
				draw_point(data, x, y, floor);
			x++;
		}
		y++;
	}
}