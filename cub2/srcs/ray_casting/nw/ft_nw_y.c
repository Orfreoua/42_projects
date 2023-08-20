/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nw_y.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:24:50 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 17:24:51 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../cub3D.h"

double	*ft_nw_y(t_data *data, double x, double y, double angle)
{
	int		i;
	double	*hypo;

	i = 1;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	hypo[0] = y / cos((PI / 2) - (angle - PI));
	data->player.hit1_x = data->player.x - sqrt(hypo[0] * hypo[0] - (y * y));
	data->player.hit1_y = (int)data->player.y;
	while (data->player.hit1_y >= 0 && data->player.hit1_x >= 0
		&& ft_check_hit(data, 'n', data->player.hit1_x,
			data->player.hit1_y) != '1')
	{
		hypo[0] = (y + i) / cos((PI / 2) - (angle - PI));
		data->player.hit1_x = data->player.x - sqrt(
				hypo[0] * hypo[0] - ((y + i) * (y + i)));
		data->player.hit1_y = (int)data->player.y - i;
		i++;
	}
	hypo[1] = ft_nw_y_1(data, x, y, angle);
	return (hypo);
}

double	ft_nw_y_1(t_data *data, double x, double y, double angle)
{
	int		i;
	double	hypo;

	(void)y;
	i = 1;
	hypo = x / cos(angle - PI);
	data->player.hit2_x = (int)data->player.x;
	data->player.hit2_y = data->player.y - sqrt(hypo * hypo - (x * x));
	while (data->player.hit2_y >= 0 && data->player.hit2_x >= 0
		&& ft_check_hit(data, 'w', data->player.hit2_x,
			data->player.hit2_y) != '1')
	{
		hypo = (x + i) / cos(angle - PI);
		data->player.hit2_x = (int)data->player.x - i;
		data->player.hit2_y = data->player.y - sqrt(
				hypo * hypo - ((x + i) * (x + i)));
		i++;
	}
	return (hypo);
}
