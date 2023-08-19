/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sw_y.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:25:33 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 17:25:36 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../cub3D.h"

double	*ft_sw_y(t_data *data, double x, double y, double angle)
{
	int		i;
	double	*hypo;

	i = 1;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	hypo[0] = (1 - y) / cos(angle - (PI / 2));
	data->player.hit1_x = (int)data->player.x + x - sqrt(
			hypo[0] * hypo[0] - ((1 - y) * (1 - y)));
	data->player.hit1_y = (int)data->player.y + 1;
	while (data->player.hit1_y <= data->map.g_height && data->player.hit1_x
		>= 0 && ft_check_hit(data, 's',
			data->player.hit1_x, data->player.hit1_y) != '1')
	{
		hypo[0] = ((1 - y) + i) / cos(angle - (PI / 2));
		data->player.hit1_x = (int)data->player.x + x - sqrt(
				hypo[0] * hypo[0] - (((1 - y) + i) * ((1 - y) + i)));
		data->player.hit1_y = (int)data->player.y + 1 + i;
		i++;
	}
	hypo[1] = ft_sw_y_1(data, x, y, angle);
	return (hypo);
}

double	ft_sw_y_1(t_data *data, double x, double y, double angle)
{
	int		i;
	double	hypo;

	i = 1;
	hypo = x / cos((PI / 2) - (angle - (PI / 2)));
	data->player.hit2_x = (int)data->player.x;
	data->player.hit2_y = (int) data->player.y + y + sqrt(hypo * hypo - (x * x));
	while (data->player.hit2_y <= data->map.g_height && data->player.hit2_x
		>= 0 && ft_check_hit(data, 'w',
			data->player.hit2_x, data->player.hit2_y) != '1')
	{
		hypo = (x + i) / cos((PI / 2) - (angle - (PI / 2)));
		data->player.hit2_x = (int)data->player.x - i;
		data->player.hit2_y = (int) data->player.y + y + sqrt(
				hypo * hypo - ((x + i) * (x + i)));
		i++;
	}
	return (hypo);
}
