/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:48:28 by orfreoua          #+#    #+#             */
/*   Updated: 2022/06/13 10:48:29 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

short	error(int return_vallue, char *msg)
{
	printf(RED "%s\n", msg);
	printf(NORMAL);
	return (return_vallue);
}

short	check_args(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
		return (error(1, "Error: bad number of arguments"));
	if (!load_arg(&data->args, argc, argv))
		return (error(1, "Error: bad argument"));
	return (0);
}
