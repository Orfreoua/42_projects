/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:22:25 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 21:49:46 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3D.h"

void	ft_keycode(int keycode, t_data *data)
{
	if (keycode == ECHAP)
	{
		ft_free_data(data);
		exit(0);
	}
	menu(data, keycode);
	if (!data->menu.ison)
	{
		ft_turn(keycode, data);
		ft_move(keycode, data);
	}
}

void	ft_turn(int keycode, t_data *data)
{
	if (keycode == ARROW_LEFT)
		data->player.angle -= 2;
	else if (keycode == ARROW_RIGHT)
		data->player.angle += 2;
	if (data->player.angle < 0)
		data->player.angle = 360 + data->player.angle;
	else if (data->player.angle > 360)
		data->player.angle = data->player.angle - 360;
}

void	ft_move(int keycode, t_data *data)
{
	double	tmp;
	if (keycode == LEFT || keycode == UP
		|| keycode == RIGHT || keycode == DOWN)
	{
		if (keycode == UP)
			tmp = (PI / 180) * data->player.angle;
		else if (keycode == LEFT)
			tmp = (PI / 180) * (data->player.angle + 270);
		else if (keycode == RIGHT)
			tmp = (PI / 180) * (data->player.angle + 90);
		else if (keycode == DOWN)
			tmp = (PI / 180) * (data->player.angle + 180);
		if (data->map.grid[(int)(data->player.y + (sin(tmp) / 25))]
			[(int)(data->player.x + (cos(tmp) / 25))] != '1')
		{
			data->player.x = (data->player.x + (cos(tmp) / 25));
			data->player.y = (data->player.y + (sin(tmp) / 25));
		}
	}
}
