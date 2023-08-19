/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:22:34 by orfreoua          #+#    #+#             */
/*   Updated: 2023/08/19 18:06:00 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../cub3D.h"

int	main(int ac, char **av)
{
	t_data data;

	data.frame = 1;
	ft_init_data(&data);
	(void)ac;
	(void)av;
	char **tab;
	tab = malloc(sizeof(char *) * 10);
	tab[0] = strdup("1111111111");
	tab[1] = strdup("1000000001");
	tab[2] = strdup("1000000001");
	tab[3] = strdup("1000000001");
	tab[4] = strdup("1000000001");
	tab[5] = strdup("1000000001");
	tab[6] = strdup("1000000001");
	tab[7] = strdup("1000000001");
	tab[8] = strdup("1000000001");
	tab[9] = strdup("1111111111");
	data.map.grid = tab;
	data.map.g_height = 10;
	data.map.g_width = 10;
	data.player.x = 2.0;
	data.player.y = 2.0;
	data.player.dir = 0;
	data.player.angle = 0;
	
	
	data.arg.so = strdup("./textures/bricksheight.xpm");
	data.arg.we = strdup("./textures/bricksheight.xpm");
	data.arg.ea  = strdup("./textures/bricksheight.xpm");
	data.arg.no = strdup("./textures/bricksheight.xpm");

	data.mlx = mlx_init();
	if (ft_init_texture(&data) < 0)
	{
		ft_free_data(&data);
		printf("Wrong texture paths\n");
		return (-1);
	}
	////
	data.win = mlx_new_window(data.mlx, S_WIDTH, S_HEIGHT, "cub3D");
	data.buff01.img = mlx_new_image(data.mlx, S_WIDTH, S_HEIGHT);
	data.buff01.addr = mlx_get_data_addr(data.buff01.img, &data.buff01.bpp,
			&data.buff01.l_len, &data.buff01.endian);
	ft_vector_1(&data, &data.buff01);
	mlx_put_image_to_window(data.mlx, data.win, data.buff01.img, 0, 0);
	mlx_hook(data.win, 33, (1L << 17), ft_exit, &data);
	mlx_hook(data.win, 2, 1L << 0, ft_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
