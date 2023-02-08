/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:57:44 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/08 19:51:52 by orfreoua         ###   ########.fr       */
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
	if (data->file.textures.north)
		free(data->file.textures.north);
	if (data->file.textures.south)
		free(data->file.textures.south);
	if (data->file.textures.east)
		free(data->file.textures.east);
	if (data->file.textures.west)
		free(data->file.textures.west);
	print_error(msg);
	exit(1);
}