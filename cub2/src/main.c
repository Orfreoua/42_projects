
#include "../cub3D.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	mlx.frame = 1;
	ft_init_data(&mlx);
	//if (ft_checking(&mlx, ac, av) < 0)
	//	return (-1);
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
	mlx.map.grid = tab;
	mlx.map.g_height = 10;
	mlx.map.g_width = 10;
	mlx.player.x = 2.0;
	mlx.player.y = 2.0;
	mlx.player.dir = 0;
	mlx.player.angle = 0;
	
	
	mlx.arg.so = strdup("./textures/bricksheight.xpm");
	mlx.arg.we = strdup("./textures/bricksheight.xpm");
	mlx.arg.ea  = strdup("./textures/bricksheight.xpm");
	mlx.arg.no = strdup("./textures/bricksheight.xpm");

	mlx.mlx = mlx_init();
	if (ft_init_texture(&mlx) < 0)
	{
		ft_free_data(&mlx);
		printf("Wrong texture paths\n");
		return (-1);
	}
	////
	mlx.win = mlx_new_window(mlx.mlx, S_WIDTH, S_HEIGHT, "cub3D");
	mlx.buff01.img = mlx_new_image(mlx.mlx, S_WIDTH, S_HEIGHT);
	mlx.buff01.addr = mlx_get_data_addr(mlx.buff01.img, &mlx.buff01.bpp,
			&mlx.buff01.l_len, &mlx.buff01.endian);
	ft_vector_1(&mlx, &mlx.buff01);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.buff01.img, 0, 0);
	mlx_hook(mlx.win, 33, (1L << 17), ft_exit, &mlx);
	mlx_hook(mlx.win, 2, 1L << 0, ft_next_frame, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

/*src/parsing/ft_map_01.c 	\
			src/parsing/ft_map_02.c 	\
			src/parsing/ft_map_03.c		\
			src/parsing/ft_map_04.c		\
			src/parsing/ft_text_parsing.c 	\
			src/parsing/ft_map_parsing_01.c	\
			src/parsing/ft_map_parsing_02.c	\
			src/colors/ft_color_01.c	\
			src/colors/ft_color_02.c	\
			src/colors/ft_convert.c		\
			
			*/