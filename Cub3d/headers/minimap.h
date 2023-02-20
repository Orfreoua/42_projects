/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:32:46 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/20 16:56:14 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# define MMRATIO_X 1
# define MMRATIO_Y 1
# define MMOFFSET_X 0
# define MMOFFSET_Y 0

# include "headers.h"

typedef struct s_minimap
{
	t_size  reso;
    t_size  cell;
    t_size  grid;
    t_point pos_player;
}	t_minimap;

#endif