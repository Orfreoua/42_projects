/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:49:39 by orfreoua          #+#    #+#             */
/*   Updated: 2022/06/13 10:49:40 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

short	ft_sleep(t_data *data, t_philo *philo)
{
	short	index;

	put_msg(data, philo->index_philo, "is sleeping", 0);
	index = ft_usleep(data, philo, philo->args.time_to_sleep);
	return (index);
}
