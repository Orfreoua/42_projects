/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:13:10 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/20 18:55:06 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	print_map(char **map, t_size grid)
{
	int	i;
	int	j;

	printf(BLU "Map2D :\n" NRM);
	printf(BLU "grid : (%dx, %dy)\n", (int)grid.width, (int)grid.height);
	printf(NRM);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				printf( BLU "%c", map[i][j]);
			else if (map[i][j] == '0')
				 printf(NRM "%c", map[i][j]);
			else
				printf(RED "%c", map[i][j]);
			j++;
		}
		printf("\n" NRM);
		i++;
	}
	printf(NRM "\n");
}

void	print_rays(t_point *rays, int limit)
{
	int	i;

	printf(BLU "Tab de rays : \n");
	i = 0;
	while (i < RESO_X && i < limit)
	{
		printf("%fx, %fy\n", rays[i].x, rays[i].y);
		i++;
	}
	printf("\n" NRM);
}

void	print_dist(double *dist, int limit)
{
	int	i;

	printf(BLU "Tab de distances : \n");
	i = 0;
	while (i < RESO_X && i < limit)
	{
		printf("%f\n", dist[i]);
		i++;
	}
	printf("\n" NRM);
}

void	print_data(t_data *data)
{
	print_map(data->file.map, data->file.grid);
	print_rays(data->rc.rays, 5);//les 5 premiers rays.
	print_dist(data->rc.distances, 5);//les 5 premierers dist.
}