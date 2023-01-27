/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:46:47 by orfreoua          #+#    #+#             */
/*   Updated: 2022/06/13 10:46:49 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	put_msg(t_data *data, int index_philo, char *msg, short died)
{
	long	time;

	if (!check_end(data, &data->philo[index_philo]))
	{
		pthread_mutex_lock(&data->mutex_for_write);
		time = current_time(data->philo->time_start);
		if (!check_end(data, &data->philo[index_philo]))
			printf("%ld %d %s\n", time, index_philo + 1, msg);
		if (died)
		{
			pthread_mutex_lock(&data->mutex_for_check_death);
			data->index_if_one_philo_dead = 1;
			pthread_mutex_unlock(&data->mutex_for_check_death);
		}
		pthread_mutex_unlock(&data->mutex_for_write);
	}
}
