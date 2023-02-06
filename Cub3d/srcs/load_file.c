/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:05:36 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/06 20:00:36 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

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

int	check_inside_file(t_data *data, int fd)
{
	char *line;

	while (get_next_line(fd, &line) > 0)
	{
		if (strncmp(line, "NO ./", 5)){}
		else if (strncmp(line, "SO ./", 5)){}
		else if (strncmp(line, "WE ./", 5)){}
		else if (strncmp(line, "EA ./", 5)){}
		else if (!data->file.textures.path_east || !data->file.textures.path_north
		|| !data->file.textures.path_ouest || !data->file.textures.path_south)
			return (print_error(MISSING_TEXTURES));
	}
}	

int	load_file(t_data *data, char *file)
{
	if (check_file(file) == ERROR)
		return (ERROR);
	if (check_inside_file(data, open(file, O_RDONLY)) == ERROR)
		return (ERROR);
	return (OK);
}
