/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:58:03 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/04 19:54:35 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
#include <stdlib.h>
# include "../mlx_linux/mlx.h"
# include "libft.h"

# define ERROR 1
# define OK 0

/*  error messages   */
# define	BAD_NB_ARG		"bad nb of arguments"
# define	EMPTY_ARG_FILE	"you have to give an argument"
# define	SECRET_FILE		"this is a secret file"
# define	BAD_NAME_FILE	"this is a bad name of file"
# define	BAD_PATH_FILE	"the path is not valid"
# define	MLX_CONNECTION	"the connection between with the display has not been established"
# define	WIN_CONNECTION	"the window could not be created"


/*  colors  */
# define	RED  			"\x1B[31m"
# define	NRM  			"\x1B[0m"

/*	key	*/
# define	UP				119
# define	DOWN			115
# define	LEFT			797
# define	RIGHT			100
# define	ESCAPE			65307

typedef struct s_assets
{
	char *path_north;
	char *path_south;
	char *path_east;
	char *path_ouest;
}	t_assets;

typedef struct s_point
{
	double		x;
	double		y;
	
}	t_point;

typedef struct s_size
{
	int			x;
	int			y;
	
}	t_size;

typedef struct s_file
{
	char		**map;
	t_size		size_map;
	t_point		pos_player;
	
}	t_file;

typedef struct s_mlx
{
	void	*ptr_mlx;
	void	*ptr_win;
}	t_mlx;

typedef struct s_data
{
	t_file	file;
	t_mlx	mlx;
}	t_data;

/*  utils.c */
int	print_error(char *msg);

/*	load_file.c	*/
int	load_file(t_data *data, char *file);

#endif