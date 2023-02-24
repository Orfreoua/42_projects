/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 05:25:17 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/24 22:42:24 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	draw_full_circle(t_data *data, int x, int y, int radius)
{
	int	ct[2];

	ct[0] = x - radius;
	while (ct[0] <= x + radius)
	{
		ct[1] = y - radius;
		while (ct[1] <= y + radius)
		{
			if ((ct[0] - x) * (ct[0] - x) + (ct[1] - y)
				* (ct[1] - y) <= radius * radius)
				draw_point(data, ct[0], ct[1], ORANGE_PEEL);
			ct[1]++;
		}
		ct[0]++;
	}
}
