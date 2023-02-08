/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:13:16 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/08 19:04:34 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	init_file(t_file *file)
{
	file->ceiling.r = -1;
	file->ceiling.g = -1;
	file->ceiling.b = -1;
	file->floor.r = -1;
	file->floor.g = -1;
	file->floor.b = -1;
	file->textures[PATH_NORTH] = 0;
	file->textures[PATH_SOUTH] = 0;
	file->textures[PATH_EAST] = 0;
	file->textures[PATH_OUEST] = 0;
	file->map = NULL;
	file->pos_player.x = -1;
	file->pos_player.y = -1;
}


int	valid_color(t_color *color)
{
	if (color->r > -1 && color->g > -1 && color->b > -1)
		return (1);
	return (0);
}

int	all_data_is_recovered(t_data *data)
{
	if (data->file.textures[PATH_OUEST] && data->file.textures[PATH_NORTH]
		&& data->file.textures[PATH_SOUTH] && data->file.textures[PATH_EAST]
		&& valid_color(&data->file.ceiling) && valid_color(&data->file.floor))
		return (1);
	return (0);
}
