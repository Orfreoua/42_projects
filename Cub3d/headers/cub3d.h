/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:58:03 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/08 18:59:28 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "headers.h"

# define ERROR 1
# define OK 0

# define RESO_X 1000
# define RESO_Y 1000

typedef enum s_textures
{
	PATH_NORTH,
	PATH_SOUTH,
	PATH_EAST,
	PATH_OUEST
}	t_textures;

typedef struct s_file
{
	char		**map;
	t_size		size;
	t_point		pos_player;	
	char		textures[4];
	t_color		ceiling;
	t_color		floor;
}	t_file;

typedef struct s_mlx
{
	void		*ptr_mlx;
	void		*ptr_win;
}	t_mlx;

typedef struct s_data
{
	t_file		file;
	t_mlx		mlx;
}	t_data;

/*  utils.c */
int	print_error(char *msg);

/*	parsing	*/
int		load_file(t_data *data, char *file);
int		all_data_is_recovered(t_data *data);
void	init_file(t_file *file);

#endif