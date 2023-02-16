/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:58:03 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/16 20:14:28 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "headers.h"

# define ERROR 1
# define OK 0

# define RESO_X 1000
# define RESO_Y 1000

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_textures;

typedef struct s_file
{
	char		**map;
	t_size		grid;
	t_point		pos_player;
	double		rotate;
	t_textures	textures;
	t_color		ceiling;
	t_color		floor;
}	t_file;

typedef struct	s_screen
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_screen;

typedef struct	s_mlx
{
	void		*ptr;
	void		*ptr_win;
	t_screen	screen;
}				t_mlx;

typedef struct	s_raycating
{
	t_point		*rays;
	double		*distances;
}				t_raycasting;

typedef struct s_data
{
	t_file			file;
	t_minimap		minimap;
	t_mlx			mlx;
	t_raycasting	rc;
}	t_data;

/*  utils.c */
int		print_error(char *msg);
void	free_error(t_data *data, char *msg);

/*	parsing	*/
int		load_file(t_data *data, char *file);
int		all_data_is_recovered(t_data *data);
void	init_file(t_file *file);
void	draw_point(t_data *data, int x, int y , int color);

void	display_minimap(t_data *data);
void	mini_map_init(t_data *data, t_minimap *minimap);

int	logic_raycasting(t_data *data);

void	draw_line(t_data *data, t_point a1, t_point a2, int color);

#endif
