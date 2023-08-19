/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nw_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:24:43 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 17:24:45 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../../cub3D.h"

double	*ft_nw_x(t_data *data, double x, double y, double angle)
{
	int		i;
	double	*hypo;

	i = 1;
	hypo = malloc(sizeof(double) * 2);
	if (hypo == NULL)
		return (NULL);
	hypo[0] = x / cos(angle - PI);
	data->player.hit1_x = (int)data->player.x;
	data->player.hit1_y = data->player.y - sqrt(hypo[0] * hypo[0] - x * (x));
	while (data->player.hit1_y >= 0 && data->player.hit1_x >= 0
		&& ft_check_hit(data, 'w', data->player.hit1_x,
			data->player.hit1_y) != '1')
	{
		hypo[0] = (x + i) / cos(angle - PI);
		data->player.hit1_x = (int)data->player.x - i;
		data->player.hit1_y = data->player.y - sqrt(
				hypo[0] * hypo[0] - ((x + i) * (x + i)));
		i++;
	}
	hypo[1] = ft_nw_x_1(data, x, y, angle);
	return (hypo);
}

double	ft_nw_x_1(t_data *data, double x, double y, double angle)
{
	int		i;
	double	hypo;

	(void)x;
	i = 1;
	hypo = y / cos((PI / 2) - (angle - PI));
	data->player.hit2_x = data->player.x - sqrt(hypo * hypo - (y * y));
	data->player.hit2_y = (int)data->player.y;
	while (data->player.hit2_y >= 0 && data->player.hit2_x >= 0
		&& ft_check_hit(data, 'n', data->player.hit2_x,
			data->player.hit2_y) != '1')
	{
		hypo = (y + i) / cos((PI / 2) - (angle - PI));
		data->player.hit2_x = data->player.x - sqrt(
				hypo * hypo - ((y + i) * (y + i)));
		data->player.hit2_y = (int)data->player.y - i;
		i++;
	}
	return (hypo);
}
