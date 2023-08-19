
#include "../../cub3D.h"

void	ft_init_data(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->map.grid = NULL;
	mlx->arg.no = NULL;
	mlx->arg.so = NULL;
	mlx->arg.ea = NULL;
	mlx->arg.we = NULL;
	mlx->text_e.img = NULL;
	mlx->text_s.img = NULL;
	mlx->text_w.img = NULL;
	mlx->text_n.img = NULL;
	mlx->buff01.img = NULL;
	mlx->buff02.img = NULL;
}

void	ft_free_grid(t_map *map)
{
	int	i;

	i = 0;
	if (map->grid)
	{
		while (map->grid[i])
		{
			if (map->grid[i])
				free(map->grid[i]);
			i++;
		}
		free(map->grid);
	}
}

void	ft_free_text(t_arg *arg)
{
	if (arg->no)
		free(arg->no);
	if (arg->ea)
		free(arg->ea);
	if (arg->so)
		free(arg->so);
	if (arg->we)
		free(arg->we);
}

void	ft_free_data(t_mlx *mlx)
{
	ft_free_grid(&mlx->map);
	ft_free_text(&mlx->arg);
	//ft_free_colors(&mlx->arg);
	if (mlx->text_e.img)
		mlx_destroy_image(mlx->mlx, mlx->text_e.img);
	if (mlx->text_s.img)
		mlx_destroy_image(mlx->mlx, mlx->text_s.img);
	if (mlx->text_w.img)
		mlx_destroy_image(mlx->mlx, mlx->text_w.img);
	if (mlx->text_n.img)
		mlx_destroy_image(mlx->mlx, mlx->text_n.img);
	if (mlx->buff01.img)
		mlx_destroy_image(mlx->mlx, mlx->buff01.img);
	if (mlx->buff02.img)
		mlx_destroy_image(mlx->mlx, mlx->buff02.img);
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}
