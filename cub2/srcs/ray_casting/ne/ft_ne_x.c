/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ne_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:24:16 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 17:24:17 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../cub3D.h"

double	*ft_ne_x(t_data *data, double x, double y, double angle)
{
	int		i;
	double	*hypo;

	i = 1;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	hypo[0] = (1 - x) / cos((2 * PI) - angle);
	data->player.hit1_x = (int)data->player.x + 1;
	data->player.hit1_y = (int)data->player.y + y
		- sqrt((hypo[0] * hypo[0]) - ((1 - x) * (1 - x)));
	while (data->player.hit1_y >= 0 && data->player.hit1_x <= data->map.g_width
		&& ft_check_hit(data, 'e', data->player.hit1_x,
			data->player.hit1_y) != '1')
	{
		hypo[0] = ((1 - x) + i) / cos((2 * PI) - angle);
		data->player.hit1_x = (int)data->player.x + 1 + i;
		data->player.hit1_y = (int)data->player.y + y - sqrt((hypo[0]
					* hypo[0]) - (((1 - x) + i) * ((1 - x) + i)));
		i++;
	}
	hypo[1] = ft_ne_x_1(data, x, y, angle);
	return (hypo);
}

double	ft_ne_x_1(t_data *data, double x, double y, double angle)
{	
	int		i;
	double	hypo;

	i = 1;
	hypo = y / cos((PI / 2) - ((2 * PI) - angle));
	data->player.hit2_x = (int)data->player.x + x + sqrt((hypo * hypo) - (y * y));
	data->player.hit2_y = (int)data->player.y;
	while (data->player.hit2_y >= 0 && data->player.hit2_x <= data->map.g_width
		&& ft_check_hit(data, 'n', data->player.hit2_x,
			data->player.hit2_y) != '1')
	{
		hypo = (y + i) / cos((PI / 2) - ((2 * PI) - angle));
		data->player.hit2_x = (int)data->player.x + x + sqrt((hypo
					* hypo) - ((y + i) * (y + i)));
		data->player.hit2_y = (int)data->player.y - i;
		i++;
	}
	return (hypo);
}
