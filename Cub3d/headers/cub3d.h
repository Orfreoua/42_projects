/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:58:03 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/02 17:27:30 by orfreoua         ###   ########.fr       */
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
# define BAD_NB_ARG		"bad nb of arguments"
# define EMPTY_ARG_FILE	"you have to give an argument"
# define SECRET_FILE	"this is a secret file"
# define BAD_NAME_FILE	"this is a bad name of file"
# define BAD_PATH_FILE	"the path is not valid"


/*  colors  */
# define RED  "\x1B[31m"
# define NRM  "\x1B[0m"

typedef struct s_file
{
	char *path_north;
	char *path_south;
	char *path_east;
	char *path_ouest;
}	t_file;

typedef struct s_data
{
	
}	t_data;

/*  utils.c */
int	print_error(char *msg);

/*	load_file.c	*/
int	load_file(t_data *data, char *file);

#endif