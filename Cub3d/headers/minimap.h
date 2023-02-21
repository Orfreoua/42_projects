/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:32:46 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/21 04:46:28 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# define MMRATIO_X 0.1
# define MMRATIO_Y 0.1
# define MMOFFSET_X 890
# define MMOFFSET_Y 890

# include "headers.h"

typedef struct s_minimap
{
	t_size  reso;
    t_size  cell;
    t_size  grid;
    t_point pos_player;
}	t_minimap;

#endif