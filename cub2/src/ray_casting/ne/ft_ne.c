/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:24:09 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 17:24:10 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../cub3D.h"

double	ft_ne(t_data *data, double x, double y, double angle)
{
	if ((1 - x) / cos((2 * PI) - angle) <= y
		/ cos((PI / 2) - ((2 * PI) - angle)))
	{
		data->ray.hypo = ft_ne_x(data, x, y, angle);
		if (data->ray.hypo == NULL)
			return (-1);
	}
	else if (y / cos((PI / 2) - ((2 * PI) - angle))
		<= (1 - x) / cos((2 * PI) - angle))
	{
		data->ray.hypo = ft_ne_y(data, x, y, angle);
		if (data->ray.hypo == NULL)
			return (-1);
	}
	return (ft_ne_1(data, x, y, angle));
}

double	ft_ne_1(t_data *data, double x, double y, double angle)
{
	double	hypo;

	if (data->ray.hypo[0] <= data->ray.hypo[1])
	{
		data->player.f_hit_x = data->player.hit1_x;
		data->player.f_hit_y = data->player.hit1_y;
		if ((1 - x) / cos((2 * PI) - angle) <= y
			/ cos((PI / 2) - ((2 * PI) - angle)))
			data->player.dir = 'e';
		else
			data->player.dir = 'n';
		hypo = data->ray.hypo[0];
		free(data->ray.hypo);
		return (hypo);
	}
	else
		return (ft_ne_2(data, x, y, angle));
	return (0);
}

double	ft_ne_2(t_data *data, double x, double y, double angle)
{
	double	hypo;

	data->player.f_hit_x = data->player.hit2_x;
	data->player.f_hit_y = data->player.hit2_y;
	if ((1 - x) / cos((2 * PI) - angle)
		<= y / cos((PI / 2) - ((2 * PI) - angle)))
		data->player.dir = 'n';
	else
		data->player.dir = 'e';
	hypo = data->ray.hypo[1];
	free(data->ray.hypo);
	return (hypo);
}
