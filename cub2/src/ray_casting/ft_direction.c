/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:23:12 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 17:23:17 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../cub3D.h"

double	ft_east(t_data *data)
{
	int	i;

	i = 0;
	while (data->player.f_hit_x <= data->map.g_width && data->map.grid
		[(int)data->player.f_hit_y][(int)data->player.f_hit_x] != '1')
	{
		data->player.f_hit_x = (int)data->player.x + i;
		data->player.f_hit_y = data->player.y;
		i++;
	}
	return (data->player.f_hit_x - data->player.x);
}

double	ft_west(t_data *data)
{
	int	i;

	i = 0;
	while (data->player.f_hit_x >= 1 && data->map.grid
		[(int)data->player.f_hit_y][(int)data->player.f_hit_x - 1] != '1')
	{
		data->player.f_hit_x = (int)data->player.x - i;
		data->player.f_hit_y = data->player.y;
		i++;
	}
	return (data->player.x - data->player.f_hit_x);
}

double	ft_south(t_data *data)
{
	int	i;

	i = 0;
	while (data->player.f_hit_y <= data->map.g_height && data->map.grid
		[(int)data->player.f_hit_y][(int)data->player.f_hit_x] != '1')
	{
		data->player.f_hit_x = data->player.x;
		data->player.f_hit_y = (int)data->player.y + i;
		i++;
	}
	return (data->player.f_hit_y - data->player.y);
}

double	ft_north(t_data *data)
{
	int	i;

	i = 0;
	while (data->player.f_hit_y >= 1 && data->map.grid
		[(int)data->player.f_hit_y - 1][(int)data->player.f_hit_x] != '1')
	{
		data->player.f_hit_x = data->player.x;
		data->player.f_hit_y = (int)data->player.y - i;
		i++;
	}
	return (data->player.y - data->player.f_hit_y);
}
