/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:25:21 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 17:25:23 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../cub3D.h"

double	ft_sw(t_data *data, double x, double y, double angle)
{
	if (x / cos((PI / 2) - (angle - (PI / 2)))
		<= (1 - y) / cos(angle - (PI / 2)))
	{
		data->ray.hypo = ft_sw_x(data, x, y, angle);
		if (data->ray.hypo == NULL)
			return (-1);
	}
	else if ((1 - y) / cos(angle - (PI / 2))
		<= x / cos((PI / 2) - (angle - (PI / 2))))
	{
		data->ray.hypo = ft_sw_y(data, x, y, angle);
		if (data->ray.hypo == NULL)
			return (-1);
	}
	return (ft_sw_1(data, x, y, angle));
}

double	ft_sw_1(t_data *data, double x, double y, double angle)
{
	double	hypo;

	if (data->ray.hypo[0] <= data->ray.hypo[1])
	{
			data->player.f_hit_x = data->player.hit1_x;
			data->player.f_hit_y = data->player.hit1_y;
		if (x / cos((PI / 2) - (angle - (PI / 2)))
			<= (1 - y) / cos(angle - (PI / 2)))
					data->player.dir = 'w';
		else
				data->player.dir = 's';
		hypo = data->ray.hypo[0];
		free(data->ray.hypo);
		return (hypo);
	}
	else
		return (ft_sw_2(data, x, y, angle));
	return (0);
}

double	ft_sw_2(t_data *data, double x, double y, double angle)
{
	double	hypo;

	data->player.f_hit_x = data->player.hit2_x;
	data->player.f_hit_y = data->player.hit2_y;
	if (x / cos((PI / 2) - (angle - (PI / 2)))
		<= (1 - y) / cos(angle - (PI / 2)))
		data->player.dir = 's';
	else
			data->player.dir = 'w';
	hypo = data->ray.hypo[1];
	free(data->ray.hypo);
	return (hypo);
}
