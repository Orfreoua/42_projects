/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 05:25:17 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/21 05:41:10 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void draw_full_circle(t_data *data, int x, int y, int radius, int color)
{
    int i;
    int j;
    double angle;
    int x1;
    int y1;
    int x2;
    int y2;
    double step = M_PI / 180.0; // convertir un degré en radian

    // Dessiner la première moitié du cercle
    for (i = 0; i < 180; i++)
    {
        angle = i * step;
        x1 = cos(angle) * radius;
        y1 = sin(angle) * radius;
        x2 = cos(angle + step) * radius;
        y2 = sin(angle + step) * radius;

        // dessiner la ligne entre deux bords du cercle
        for (j = x + x1; j < x + x2; j++)
        {
            draw_point(data, j, y + y1, color);
        }
    }

    // Dessiner la deuxième moitié du cercle
    for (i = 0; i < 180; i++)
    {
        angle = (i + 180) * step;
        x1 = cos(angle) * radius;
        y1 = sin(angle) * radius;
        x2 = cos(angle + step) * radius;
        y2 = sin(angle + step) * radius;

        // dessiner la ligne entre deux bords du cercle
        for (j = x + x1; j < x + x2; j++)
        {
            draw_point(data, j, y + y1, color);
        }
    }

    // Remplir l'intérieur du cercle
    for (i = x - radius; i <= x + radius; i++)
    {
        for (j = y - radius; j <= y + radius; j++)
        {
            if ((i - x) * (i - x) + (j - y) * (j - y) <= radius * radius)
            {
                draw_point(data, i, j, color);
            }
        }
    }
}


void draw_circle(void *mlx_ptr, void *win_ptr, int x, int y, int radius, int color)
{
    int i;
    double angle;
    int x1;
    int y1;
    int x2;
    int y2;
    double step = M_PI / 180.0; // convertir un degré en radian

    for (i = 0; i < 360; i++)
    {
        angle = i * step;
        x1 = cos(angle) * radius;
        y1 = sin(angle) * radius;
        x2 = cos(angle + step) * radius;
        y2 = sin(angle + step) * radius;

        mlx_pixel_put(mlx_ptr, win_ptr, x + x1, y + y1, color);
        mlx_pixel_put(mlx_ptr, win_ptr, x + x2, y + y2, color);
    }
}