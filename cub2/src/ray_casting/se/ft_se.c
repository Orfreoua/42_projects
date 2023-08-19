/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_se.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:25:02 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 17:25:03 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../cub3D.h"

double	ft_se(t_data *data, double x, double y, double angle)
{
	if ((1 - x) / cos(angle) <= (1 - y) / cos(PI / 2 - angle))
	{
		data->ray.hypo = ft_se_x(data, x, y, angle);
		if (data->ray.hypo == NULL)
			return (-1);
	}
	else if ((1 - y) / cos(PI / 2 - angle) <= (1 - x) / cos(angle))
	{
		data->ray.hypo = ft_se_y(data, x, y, angle);
		if (data->ray.hypo == NULL)
			return (-1);
	}
	return (ft_se_1(data, x, y, angle));
}

double	ft_se_1(t_data *data, double x, double y, double angle)
{
	double	hypo;

	if (data->ray.hypo[0] <= data->ray.hypo[1])
	{
		data->player.f_hit_x = data->player.hit1_x;
		data->player.f_hit_y = data->player.hit1_y;
		if ((1 - x) / cos(angle) <= (1 - y) / cos(PI / 2 - angle))
			data->player.dir = 'e';
		else
			data->player.dir = 's';
		hypo = data->ray.hypo[0];
		free(data->ray.hypo);
		return (hypo);
	}
	else
		return (ft_se_2(data, x, y, angle));
}

double	ft_se_2(t_data *data, double x, double y, double angle)
{
	double	hypo;

	data->player.f_hit_x = data->player.hit2_x;
	data->player.f_hit_y = data->player.hit2_y;
	if ((1 - x) / cos(angle) <= (1 - y) / cos(PI / 2 - angle))
		data->player.dir = 's';
	else
		data->player.dir = 'e';
	hypo = data->ray.hypo[1];
	free(data->ray.hypo);
	return (hypo);
}
