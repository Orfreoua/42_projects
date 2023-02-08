/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:57:44 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/08 19:35:02 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	print_error(char *msg)
{
	ft_putstr_fd(STDERR_FILENO, RED);
	ft_putstr_fd(STDERR_FILENO, "Error : ");
	ft_putstr_fd(STDERR_FILENO, msg);
	ft_putstr_fd(STDERR_FILENO, NRM);
	write(STDERR_FILENO, "\n", 1);
	return (ERROR);
}

void	free_error(t_data *data, char *msg)
{
	//if (data->file.map) la faut free un tableau de tableaus
	if (data->file.textures[PATH_NORTH])
		free(data->file.textures[PATH_NORTH]);
	if (data->file.textures[PATH_SOUTH])
		free(data->file.textures[PATH_SOUTH]);
	if (data->file.textures[PATH_EAST])
		free(data->file.textures[PATH_EAST]);
	if (data->file.textures[PATH_OUEST])
		free(data->file.textures[PATH_OUEST]);
	print_error(msg);
	exit(1);
}