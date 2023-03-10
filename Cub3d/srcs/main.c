/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:57:30 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/24 23:52:42 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	end(t_data *data)
{
	mlx_destroy_window(data->mlx.ptr, data->mlx.ptr_win);
	exit(0);
	return (0);
}

void	init_pour_test(t_data *data)
{
	char	**map;

	map = malloc(sizeof(char *) * 5);
	map[0] = ft_strdup("1111");
	map[1] = ft_strdup("1001");
	map[2] = ft_strdup("10N1");
	map[3] = ft_strdup("1111");
	map[4] = 0;
	data->file.pos_player.x = 2;
	data->file.pos_player.y = 2;
	data->file.map = map;
	data->file.grid.height = 4.0;
	data->file.grid.width = 4.0;
	data->file.pos_player.x = 2;
	data->file.pos_player.y = 2;
	data->minimap.pos_player.y = (data->file.pos_player.y * data->minimap.cell.height)
		+ (data->minimap.cell.height / 2) + data->minimap.mmoffset.height;
	data->minimap.pos_player.x = (data->file.pos_player.x * data->minimap.cell.width)
		+ (data->minimap.cell.width / 2) + data->minimap.mmoffset.width;
	data->file.rotate = M_PI / 2;
}

int	key_hook(int key, t_data *data)
{
	(void)data;
	if (key == ESCAPE)
		end(data);
	else if (key == R_RIGHT)
			data->file.rotate += (1 / (2 * M_PI)) / 2;
	else if (key == R_LEFT)
			data->file.rotate -= (1 / (2 * M_PI)) / 2;
	else if (key == UP)
	{
		if (!get_file_position(data, data->minimap.pos_player.x
				+ cos(data->file.rotate), data->minimap.pos_player.y - sin(data->file.rotate)))
		{
			data->minimap.pos_player.x += cos(data->file.rotate);
			data->minimap.pos_player.y -= sin(data->file.rotate);
		}
	}
	if (logic_raycasting(data) == ERROR)
		exit (1);
	draw_background(data);
	raycasting(data);
	display_minimap(data);
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
	data.mlx.screen.ptr = mlx_new_image(data.mlx.ptr, RESO_X, RESO_Y);
	data.mlx.screen.addr = mlx_get_data_addr(data.mlx.screen.ptr,
			&data.mlx.screen.bpp, &data.mlx.screen.line_length,
			&data.mlx.screen.endian);
	init_pour_test(&data);
	mini_map_init(&data, &data.minimap);
	mlx_hook(data.mlx.ptr_win, 2, 1L << 0, key_hook, &data);
	mlx_hook(data.mlx.ptr_win, 33, 1L << 5, end, &data);
	mlx_loop(data.mlx.ptr);
	return (0);
}
