/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:23:41 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 17:23:43 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../cub3D.h"

int	ft_init_texture(t_data *data)
{
	data->text_e.img = mlx_xpm_file_to_image(data->mlx, data->arg.ea,
			&data->text_e.img_width, &data->text_e.img_height);
	data->text_s.img = mlx_xpm_file_to_image(data->mlx, data->arg.so,
			&data->text_s.img_width, &data->text_s.img_height);
	data->text_w.img = mlx_xpm_file_to_image(data->mlx, data->arg.we,
			&data->text_w.img_width, &data->text_w.img_height);
	data->text_n.img = mlx_xpm_file_to_image(data->mlx, data->arg.no,
			&data->text_n.img_width, &data->text_n.img_height);
	if (data->text_e.img && data->text_s.img && data->text_w.img
		&& data->text_n.img)
		ft_init_texture_2(data);
	else
		return (-1);
	return (0);
}

void	ft_init_texture_2(t_data *data)
{
	data->text_e.addr = mlx_get_data_addr
		(data->text_e.img, &data->text_e.bit_per_pixel,
			&data->text_e.line_lenght, &data->text_e.endian);
	data->text_s.addr = mlx_get_data_addr
		(data->text_s.img, &data->text_s.bit_per_pixel, &data->text_s.line_lenght,
			&data->text_s.endian);
	data->text_w.addr = mlx_get_data_addr
		(data->text_w.img, &data->text_w.bit_per_pixel,
			&data->text_w.line_lenght, &data->text_w.endian);
	data->text_n.addr = mlx_get_data_addr
		(data->text_n.img, &data->text_n.bit_per_pixel, &data->text_n.line_lenght,
			&data->text_n.endian);
}

double	ft_hit(t_data *data)
{
	double	hit;

	if (data->player.dir == 'e')
		hit = data->player.f_hit_y - (int)data->player.f_hit_y;
	else if (data->player.dir == 'n')
		hit = data->player.f_hit_x - (int)data->player.f_hit_x;
	else if (data->player.dir == 'w')
		hit = (int)data->player.f_hit_y + 1 - data->player.f_hit_y;
	else if (data->player.dir == 's')
		hit = (int)data->player.f_hit_x + 1 - data->player.f_hit_x;
	return (hit);
}

unsigned int	ft_get_pixel(t_data *data, t_text *text, int w_pix, int w_size)
{
	int	x;
	int	y;
	int	diff;

	x = (int)nearbyint(ft_hit(data) * (double)text->img_width);
	y = (int)nearbyint(((double)w_pix / (double)w_size) * text->img_height);
	diff = (data->ray.wall_height - S_HEIGHT);
	if (data->ray.wall_height > S_HEIGHT)
		y = (int)nearbyint(((double)(w_pix + diff / 2)
					/ (double)data->ray.wall_height) * text->img_height);
	return (*(unsigned int *)(text->addr + (y * text->line_lenght
			+ x * (text->bit_per_pixel / 8))));
}

t_text	*ft_choose_text(t_data *data)
{
	if (data->player.dir == 'e')
		return (&data->text_e);
	else if (data->player.dir == 's')
		return (&data->text_s);
	else if (data->player.dir == 'w')
		return (&data->text_w);
	else if (data->player.dir == 'n')
		return (&data->text_n);
	return (NULL);
}
