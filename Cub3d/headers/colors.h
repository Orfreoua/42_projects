/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 20:18:47 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/20 18:16:26 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define RED "\x1B[31m"
# define BLU "\x1B[34m"
# define NRM "\x1B[0m"

typedef struct s_color
{
    int r;
    int g;
    int b;
}	t_color;

#endif