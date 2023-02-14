/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:51:32 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/14 19:58:17 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

/*
** Draw point in the current image
*/
void	draw_point(t_data *data, int x, int y , int color)
{
	char	*dst;

	if (y >= 0 && y <= RESO_Y && x >= 0 && x <= RESO_X)
	{
		dst = data->mlx.screen.addr + (y * data->mlx.screen.line_length + x * (data->mlx.screen.bpp >> 3));
		*(unsigned int*)dst = color;
	}
}