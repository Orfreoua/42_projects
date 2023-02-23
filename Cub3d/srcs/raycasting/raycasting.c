/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:37:21 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/23 18:46:14 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

#define WALL_HEIGHT 1
#define DIST_PROJ_PLANE 1

/*
void raycasting(t_data *data)
{
    int x;
    t_point point_on_floor;
    t_point point_on_ceiling;

    x = 0;
    while (x < RESO_X)
    {
        // Récupération de la distance de la caméra au mur le plus proche pour le pixel en question
        float distance_to_wall = data->rc.distances[x];

        // Calcul de la hauteur du mur en fonction de la distance de la caméra
        float wall_height = (WALL_HEIGHT / distance_to_wall) * DIST_PROJ_PLANE;

        // Calcul de la position du point sur le sol
        point_on_floor.x = x;
        point_on_floor.y = wall_height / 2;

        // Calcul de la position du point sur le plafond
        point_on_ceiling.x = x;
        point_on_ceiling.y = RESO_Y - (wall_height / 2);

        // Dessin d'une ligne reliant le point sur le sol au point sur le plafond
        draw_line(data, point_on_floor, point_on_ceiling, 0xB4D7B8);
        
        x++;
    }
}*/

void raycasting(t_data *data)
{
	int cpt = 0;
	int nb_rays = RESO_X;
	t_point p1;
	t_point p2;
	//
	cpt = 0;

	while (cpt < nb_rays)
	{
		p1.x = nb_rays - cpt;
		p2.x = nb_rays - cpt;

		p1.y = data->rc.distances[cpt];
		
		p2.y = RESO_Y - p1.y;
		draw_line(data, p1, p2,0xB4D7B8);
		//printf("DD %d : %f\n",cpt,data->distances[cpt]);
		cpt++;
	}
}