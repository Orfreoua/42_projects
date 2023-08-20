/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_se_y.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:25:14 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 17:25:15 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../cub3D.h"

double	*ft_se_y(t_data *data, double x, double y, double angle)
{
	int		i;
	double	*hypo;

	i = 0;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	while (data->player.hit1_y <= data->map.g_height && data->player.hit1_x
		<= data->map.g_width && ft_check_hit(data, 's',
			data->player.hit1_x, data->player.hit1_y) != '1')
	{
		hypo[0] = ((1 - y) + i) / cos(PI / 2 - angle);
		data->player.hit1_x = (int)data->player.x + x + sqrt(
				hypo[0] * hypo[0] - (((1 - y) + i) * ((1 - y) + i)));
		data->player.hit1_y = (int)data->player.y + i + 1;
		i++;
	}
	hypo[1] = ft_se_y_1(data, x, y, angle);
	return (hypo);
}

double	ft_se_y_1(t_data *data, double x, double y, double angle)
{
	int		i;
	double	hypo;

	i = 0;
	while (data->player.hit2_y <= data->map.g_height && data->player.hit2_x
		<= data->map.g_width && ft_check_hit(data, 'e',
			data->player.hit2_x, data->player.hit2_y) != '1')
	{
		hypo = ((1 - x) + i) / cos(angle);
		data->player.hit2_x = (int)data->player.x + i + 1;
		data->player.hit2_y = (int)data->player.y + y + sqrt(
				hypo * hypo - (((1 - x) + i) * ((1 - x) + i)));
		i++;
	}
	return (hypo);
}
