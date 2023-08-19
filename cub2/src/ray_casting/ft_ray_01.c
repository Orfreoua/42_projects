/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:23:24 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 17:23:26 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../cub3D.h"

void	ft_init_ray(t_data *data)
{
	data->player.hit1_x = data->player.x;
	data->player.hit1_y = data->player.y;
	data->player.hit2_x = data->player.x;
	data->player.hit2_y = data->player.y;
	data->player.f_hit_x = data->player.x;
	data->player.f_hit_y = data->player.y;
}

double	ft_move_angle(double angle, double move)
{
	angle = angle + move;
	if (angle <= 0)
		angle = 360 + angle;
	if (angle >= 360)
		angle = angle - 360;
	return (angle);
}

int	ft_angle(double angle)
{
	if (angle == 0 || angle == 360)
		return (1);
	else if (angle == 90)
		return (2);
	else if (angle == 180)
		return (3);
	else if (angle == 270)
		return (4);
	else if (angle > 0 && angle < 90)
		return (5);
	else if (angle > 90 && angle < 180)
		return (6);
	else if (angle > 180 && angle < 270)
		return (7);
	else if (angle > 270 && angle < 360)
		return (8);
	return (-1);
}

double	ft_ray_caster(t_data *data, double x, double y, double angle)
{
	int		direction;
	double	hypo;

	direction = ft_angle(angle / (PI / 180));
	ft_init_ray(data);
	if (direction == 1)
		hypo = ft_east(data);
	else if (direction == 2)
		hypo = ft_south(data);
	else if (direction == 3)
		hypo = ft_west(data);
	else if (direction == 4)
		hypo = ft_north(data);
	else if (direction == 5)
		hypo = ft_se(data, x, y, angle);
	else if (direction == 6)
		hypo = ft_sw(data, x, y, angle);
	else if (direction == 7)
		hypo = ft_nw(data, x, y, angle);
	else if (direction == 8)
		hypo = ft_ne(data, x, y, angle);
	return (hypo);
}

char	ft_check_hit(t_data *data, char hit, double x, double y)
{
	if (hit == 'e')
		return (data->map.grid[(unsigned int)y][(unsigned int)x]);
	else if (hit == 's')
		return (data->map.grid[(unsigned int)y][(unsigned int)x]);
	else if (hit == 'w')
		return (data->map.grid[(unsigned int)y][(unsigned int)(x - 1)]);
	else if (hit == 'n')
		return (data->map.grid[(unsigned int)(y - 1)][(unsigned int)x]);
	return ('1');
}
