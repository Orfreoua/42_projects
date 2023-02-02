/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:05:36 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/02 15:31:58 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	check_file(char *name)
{
	int	len_name;
	int	fd;

	len_name = ft_strlen(name);
	if (!len_name)
		return (print_error(EMPTY_ARG_FILE));
	if (name[0] == '.')
		return (print_error(SECRET_FILE));
	if (name[len_name - 1] != 'b' || name[len_name - 2] != 'u'
		|| name[len_name - 3] != 'c' || name[len_name - 4] != '.')
		return (print_error(BAD_NAME_FILE));
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (print_error(BAD_PATH_FILE));
	close(fd);
	return (OK);
}

int	load_file(char *file)
{
	if (check_file(file) == ERROR)
		return (ERROR);
	return (OK);
}
