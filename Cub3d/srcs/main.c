/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:57:30 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/08 19:27:52 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	end(t_data *data)
{
	mlx_destroy_window(data->mlx.ptr_mlx, data->mlx.ptr_win);
	exit(0);
	//free_map
	return (0);
}

int	key_hook(int key, t_data *data)
{
	(void)data;
	if (key == ESCAPE)
		end(data);
	return (OK);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2 || argc > 3)
		return (print_error(BAD_NB_ARG));
	data.mlx.ptr_mlx = mlx_init();
	if (!data.mlx.ptr_mlx)
		return (print_error(MLX_CONNECTION));
	if (load_file(&data, argv[1]) == ERROR)
		return (ERROR);
	data.mlx.ptr_win = mlx_new_window(data.mlx.ptr_mlx, RESO_X, RESO_Y, "");
	if (!data.mlx.ptr_win)
		return (print_error(WIN_CONNECTION));
	mlx_hook(data.mlx.ptr_win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.mlx.ptr_win, 33, 1L << 5, end, &data);
	mlx_loop(data.mlx.ptr_mlx);
	return (0);
}
