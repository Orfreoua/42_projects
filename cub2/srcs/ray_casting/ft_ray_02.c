/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:23:32 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 22:09:41 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../cub3D.h"

void	ft_vector_1(t_data *data, t_img *buff)
{
	int		i;
	double	angle;
	double	tmp;

	i = 0;
	angle = ft_move_angle(data->player.angle, -30);
	while (i < R_WIDTH)
	{
		tmp = (PI / 180) * angle;
		ft_vector_2(data, angle, tmp);
		if (data->ray.wall_height > R_HEIGHT)
			data->ray.f_wall_height = R_HEIGHT;
		ft_draw_col_c(buff, i, (R_HEIGHT - data->ray.wall_height) / 2,
			F_COLOR);
		ft_draw_col_f(buff, i, R_HEIGHT / 2, C_COLOR);
		ft_draw_t_col(data, buff, i, (R_HEIGHT - data->ray.f_wall_height) / 2);
		angle = ft_move_angle(angle, 0.06);
		i++;
	}
}

void	ft_vector_2(t_data *data, double angle, double tmp)
{
	data->ray.dist = ft_ray_caster(data, data->player.x - (int)data->player.x,
			data->player.y - (int)data->player.y, tmp);
	data->ray.wall_height = (int)nearbyint((1 / data->ray.dist) * R_HEIGHT);
	data->ray.wall_height = (int)nearbyint(data->ray.wall_height
			* (1 / cos((PI / 180) * (data->player.angle - angle))));
	data->ray.f_wall_height = data->ray.wall_height;
}
