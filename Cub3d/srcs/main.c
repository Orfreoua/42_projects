/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:57:30 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/14 20:33:59 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	end(t_data *data)
{
	mlx_destroy_window(data->mlx.ptr, data->mlx.ptr_win);
	exit(0);
	//free_map
	return (0);
}

int	key_hook(int key, t_data *data)
{
	(void)data;
	if (key == ESCAPE)
		end(data);
	if (key == UP)
	{
		mini_map_init(data, &data->minimap);
		display_minimap(data);
	}
	return (OK);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2 || argc > 3)
		return (print_error(BAD_NB_ARG));
	if (load_file(&data, argv[1]) == ERROR)
		return (ERROR);
	data.mlx.ptr = mlx_init();
	if (!data.mlx.ptr)
		return (print_error(MLX_CONNECTION));
	data.mlx.ptr_win = mlx_new_window(data.mlx.ptr, RESO_X, RESO_Y, "");
	if (!data.mlx.ptr_win)
		return (print_error(WIN_CONNECTION));
	data.mlx.screen.bpp = 0;
	data.mlx.screen.line_length = 0;
	data.mlx.screen.endian = 0;
	data.mlx.screen.ptr = mlx_new_image(data.mlx.ptr,
					RESO_X, RESO_Y);
	data.mlx.screen.addr =  mlx_get_data_addr(data.mlx.screen.ptr, &data.mlx.screen.bpp,
					&data.mlx.screen.line_length, &data.mlx.screen.endian);
	mlx_hook(data.mlx.ptr_win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.mlx.ptr_win, 33, 1L << 5, end, &data);
	mlx_loop(data.mlx.ptr);
	return (0);
}
