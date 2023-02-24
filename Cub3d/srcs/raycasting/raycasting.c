/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:37:21 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/24 23:30:36 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

#define WALL_HEIGHT 1
#define DIST_PROJ_PLANE 1

void	raycasting(t_data *data)
{
	int		cpt;
	int		nb_rays;
	t_point	p1;
	t_point	p2;

	cpt = 0;
	nb_rays = RESO_X;
	while (cpt < nb_rays)
	{
		p1.x = nb_rays - cpt;
		p2.x = nb_rays - cpt;
		p1.y = data->rc.distances[cpt];
		p2.y = RESO_Y - p1.y;
		draw_line(data, p1, p2, 0xB4D7B8);
		cpt++;
	}
}
