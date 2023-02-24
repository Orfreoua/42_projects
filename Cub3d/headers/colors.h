/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:18:47 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/24 23:39:04 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define RED "\x1B[31m"
# define BLU "\x1B[34m"
# define NRM "\x1B[0m"

# define ORANGE_PEEL 0xFFA500
# define WHEAT_BEIGE 0xF5DEB3
# define BABY_BLUE 0x87CEEB
# define LAVENDER_MIST 0xE6E6FA

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

#endif