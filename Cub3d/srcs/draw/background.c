/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 05:03:38 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/24 21:35:40 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_background(t_data *data)
{
	int	x;
	int	y;
	int	floor;
	int	ceiling;

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
