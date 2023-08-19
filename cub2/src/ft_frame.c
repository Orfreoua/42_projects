/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_frame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:22:17 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 19:08:39 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3D.h"

int	ft_next_frame(int keycode, t_data *data)
{
	if (data->frame % 2 != 0)
	{
		data->buff02.img = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
		data->buff02.addr = mlx_get_data_addr(data->buff02.img, &data->buff02.bpp,
				&data->buff02.l_len, &data->buff02.endian);
		ft_keycode(keycode, data);
		ft_vector_1(data, &data->buff02);
		mlx_put_image_to_window(data->mlx, data->win, data->buff02.img, 0, 0);
		mlx_destroy_image(data->mlx, data->buff01.img);
		if (data->menu.ison)
			display_menu(data);
	}
	else
	{
		data->buff01.img = mlx_new_image(data->mlx, S_WIDTH, S_HEIGHT);
		data->buff01.addr = mlx_get_data_addr(data->buff01.img, &data->buff01.bpp,
				&data->buff01.l_len, &data->buff01.endian);
		ft_keycode(keycode, data);
		ft_vector_1(data, &data->buff01);
		mlx_put_image_to_window(data->mlx, data->win, data->buff01.img, 0, 0);
		mlx_destroy_image(data->mlx, data->buff02.img);
		if (data->menu.ison)
			display_menu(data);
	}
	data->frame++;
	return (0);
}
