/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:24:35 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 17:24:37 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../cub3D.h"

double	ft_nw(t_data *data, double x, double y, double angle)
{
	if (x / cos(angle - PI) <= y / cos((PI / 2) - (angle - PI)))
	{
		data->ray.hypo = ft_nw_x(data, x, y, angle);
		if (data->ray.hypo == NULL)
			return (-1);
	}
	else if (y / cos((PI / 2) - (angle - PI)) <= x / cos(angle - PI))
	{
		data->ray.hypo = ft_nw_y(data, x, y, angle);
		if (data->ray.hypo == NULL)
			return (-1);
	}
	return (ft_nw_1(data, x, y, angle));
}

double	ft_nw_1(t_data *data, double x, double y, double angle)
{
	double	hypo;

	if (data->ray.hypo[0] <= data->ray.hypo[1])
	{
		data->player.f_hit_x = data->player.hit1_x;
		data->player.f_hit_y = data->player.hit1_y;
		if (x / cos(angle - PI) <= y / cos((PI / 2) - (angle - PI)))
			data->player.dir = 'w';
		else
			data->player.dir = 'n';
		hypo = data->ray.hypo[0];
		free(data->ray.hypo);
		return (hypo);
	}
	else
		return (ft_nw_2(data, x, y, angle));
	return (0);
}

double	ft_nw_2(t_data *data, double x, double y, double angle)
{
	double	hypo;

	data->player.f_hit_x = data->player.hit2_x;
	data->player.f_hit_y = data->player.hit2_y;
	if (x / cos(angle - PI) <= y / cos((PI / 2) - (angle - PI)))
		data->player.dir = 'n';
	else
		data->player.dir = 'w';
	hypo = data->ray.hypo[1];
	free(data->ray.hypo);
	return (hypo);
}
