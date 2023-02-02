/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:05:36 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/02 16:41:31 by orfreoua         ###   ########.fr       */
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

int	check_inside_file(t_data *data, char *file)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (print_error(BAD_PATH_FILE));
	
	close(fd);
	return (OK);
}

int	load_file(t_data *data, char *file)
{
	if (check_file(file) == ERROR)
		return (ERROR);
	if (check_inside_file(data, file) == ERROR)
		return (ERROR);
	return (OK);
}
