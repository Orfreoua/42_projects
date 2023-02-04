/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:57:30 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/04 17:32:30 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2 || argc > 3)
		return (print_error(BAD_NB_ARG));
	if (load_file(&data, argv[1]) == ERROR)
		return (ERROR);
	
	return (0);
}
