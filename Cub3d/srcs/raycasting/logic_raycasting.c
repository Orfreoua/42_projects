/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:28:50 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/16 22:05:20 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

double	sqr(double a)
{
	return (a * a);
}

double	get_distance(t_point p1, t_point p2)
{
	return (sqrt(sqr(p2.y - p1.y) + sqr(p2.x - p1.x)));
}

int get_file_position(t_data *data, t_point p)
{
	int x;
	int	y;

	x = (int)(p.x / data->minimap.cell.width);
	y = (int)(p.y / data->minimap.cell.height);
	if (data->file.map[y][x] && data->file.map[y][x] == '0')
		return 0;
	return 1;
}

int	load_distances(t_data *data, double first, double last, double slice)
{
	t_point p;	
	double	dist;
	int cpt_ray;

	data->rc.rays = malloc(sizeof(t_point) * (int)RESO_X);
	data->rc.distances = malloc(sizeof(double) * (int)RESO_X);
	if (!data->rc.rays || !data->rc.distances)
		return (ERROR);
	cpt_ray = 0;
	while (first < last)
	{
		dist = 0;
		while (1)
		{
			p.x = data->minimap.pos_player.x + (cos(first) * dist);
			p.y = data->minimap.pos_player.y - (sin(first) * dist);
			if (get_file_position(data, p))
			{
				data->rc.rays[cpt_ray] = p;
				break;
			}
			dist += 0.1;
		}
		data->rc.distances[cpt_ray] = get_distance(data->minimap.pos_player, data->rc.rays[cpt_ray]);
		cpt_ray++;
		first += slice;	
	}
	return (OK);
}

int	logic_raycasting(t_data *data)
{
	//pour test
	data->file.rotate = M_PI / 2;
	//
	double	first_degree;
	double	last_degree;
	double	slice;

	first_degree = data->file.rotate - M_PI / 6;
	last_degree = data->file.rotate + M_PI / 6;
	slice = (last_degree - first_degree) / RESO_X;
	if (load_distances(data, first_degree, last_degree, slice) == ERROR)
		return (ERROR);
	return (OK);
}