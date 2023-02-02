/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:57:44 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/02 15:00:19 by orfreoua         ###   ########.fr       */
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
