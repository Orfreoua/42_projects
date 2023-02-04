/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:58:03 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/04 20:26:40 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "headers.h"

# define ERROR 1
# define OK 0

typedef struct s_assets
{
	char		*path_north;
	char		*path_south;
	char		*path_east;
	char		*path_ouest;
}	t_assets;

typedef struct s_file
{
	char		**map;
	t_size		size_map;
	t_point		pos_player;	
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

/*	load_file.c	*/
int	load_file(t_data *data, char *file);

#endif