/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:57:30 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/04 18:23:32 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	key_hook(int key, t_data *data)
{
	(void)data;
	ft_putnbr_fd(STDERR_FILENO, key);
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
	data.mlx.ptr_win = mlx_new_window(data.mlx.ptr_mlx, data.file.size_map.x, data.file.size_map.y, "");
	if (!data.mlx.ptr_win)
		return (print_error(WIN_CONNECTION));
	mlx_hook(data.mlx.ptr_win, 2, 1L << 0, key_hook, &data);
	/*mlx_loop_hook(data->mlx.init, update, data);
	mlx_hook(data->mlx.win, 2, 1L << 0, key_hook, data);
	mlx_hook(data->mlx.win, 33, 1L << 5, free_all, data);
	mlx_loop(data->mlx.init);*/
	mlx_loop(data.mlx.ptr_mlx);
	mlx_destroy_window(data.mlx.ptr_mlx, data.mlx.ptr_win);
	return (0);
}
