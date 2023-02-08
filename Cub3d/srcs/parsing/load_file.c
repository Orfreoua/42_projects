/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:05:36 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/08 20:04:08 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	check_file(char *file)
{
	int	len_name;
	int	fd;

	len_name = ft_strlen(file);
	if (!len_name)
		return (print_error(EMPTY_ARG_FILE));
	if (file[0] == '.')
		return (print_error(SECRET_FILE));
	if (file[len_name - 4] != '.' || file[len_name - 3] != 'c'
		|| file[len_name - 2] != 'u' || file[len_name - 1] != 'b')
		return (print_error(BAD_NAME_FILE));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (print_error(BAD_PATH_FILE));
	close(fd);
	return (OK);
}

void	load_path(t_data *data, char *line, char **path, int fd)
{
	if (*path)
	{
		printf("%s\n", *path);
		free(line);
		close(fd);
		free_error(data, DOUBLE_SAME_PATH);
	}
	/*if (data->file.textures[index])
	{
		printf("%s\n", data->file.textures[index]);
		free(line);
		close(fd);
		free_error(data, DOUBLE_SAME_PATH);
	}
	data->file.textures[index] = ft_strdup(line);
	if (!data->file.textures[index])
	{
		free(line);
		close(fd);
		free_error(data, MALLOC_FAILED);
	}
	printf("%s\n", data->file.textures[index]);*/
}

int	check_inside_file(t_data *data, int fd)
{
	char	*line;
	int		nb;

	nb = 0;
	if (fd == -1)
		return (print_error(BAD_PATH_FILE));
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strncmp(line, "NO ", 3))
			load_path(data, line, &data->file.textures.north, fd);
		else if (ft_strncmp(line, "SO ", 3))
			load_path(data, line, &data->file.textures.south, fd);
		else if (ft_strncmp(line, "EA ", 3))
			load_path(data, line, &data->file.textures.east, fd);
		else if (ft_strncmp(line, "WE ", 3))
			load_path(data, line, &data->file.textures.west, fd);
	/*	else if (ft_strncmp(line, "F ", 2)){}
		//else if (ft_strncmp(line, "C ", 2)){}*/
		else
			break;
		nb++;
		if (all_data_is_recovered(data))
			break ;
	}
	//		return (print_error(MISSING_TEXTURES));*/
	return (OK);
}	

int	load_file(t_data *data, char *file)
{
	if (check_file(file) == ERROR)
		return (ERROR);
	init_file(&data->file);
	if (check_inside_file(data, open(file, O_RDONLY)) == ERROR)
		return (ERROR);
	return (OK);
}
