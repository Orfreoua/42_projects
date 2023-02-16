/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:51:32 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/16 21:43:16 by orfreoua         ###   ########.fr       */
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

void	restrain_pos(t_point *pos, t_point *win)
{
	if (pos->x < 0)
		pos->x = 0;
	if (pos->x > win->x)
		pos->x = win->x - 1;
	if (pos->y < 0)
		pos->y = 0;
	if (pos->y > win->y)
		pos->y = win->y - 1;
}

void	draw_line(t_data *data, t_point a1, t_point a2, int color)
{
	double	deltax;
	double	deltay;
	double	step;
	t_point	win;

	win.x = RESO_X;
	win.y = RESO_Y;
	restrain_pos(&a1, &win);
	restrain_pos(&a2, &win);
	deltax = a2.x - a1.x;
	deltay = a2.y - a1.y;
	if (fabs(deltax) > fabs(deltay))
		step = fabs(deltax);
	else
		step = fabs(deltay);
	deltax /= step;
	deltay /= step;
	while (fabs(a2.x - a1.x) > 0.5 || fabs(a2.y - a1.y) > 0.5)
	{
		draw_point(data, a1.x, a1.y, color);
		a1.x += deltax;
		a1.y += deltay;
	}
}

