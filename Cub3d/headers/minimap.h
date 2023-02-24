/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:32:46 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/24 23:49:07 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# define MMRATIO_X 0.2
# define MMRATIO_Y 0.2

# include "headers.h"

typedef struct s_minimap
{
	t_size	mmoffset;
	t_size	reso;
	t_size	cell;
	t_size	grid;
	t_point	pos_player;
	t_point	center;
	double	radius;
}	t_minimap;

#endif