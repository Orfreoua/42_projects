/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:51:14 by orfreoua          #+#    #+#             */
/*   Updated: 2022/06/13 10:51:15 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	destroy_mutex_philo(t_data *data)
{
	short	i;

	i = 0;
	while (i < 200)
	{
		pthread_mutex_destroy(&data->mutex_fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->mutex_for_check_fork);
	pthread_mutex_destroy(&data->mutex_for_write);
	pthread_mutex_destroy(&data->mutex_for_check_death);
	pthread_mutex_destroy(&data->mutex_for_check_nb_meals);
	pthread_mutex_destroy(&data->mutex_for_check_last_meal);
}

void	launch_pthread_mutex_init(t_data *data)
{
	short	i;

	i = 0;
	while (i < 200)
	{
		pthread_mutex_init(&data->mutex_fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->mutex_for_check_fork, NULL);
	pthread_mutex_init(&data->mutex_for_write, NULL);
	pthread_mutex_init(&data->mutex_for_check_death, NULL);
	pthread_mutex_init(&data->mutex_for_check_nb_meals, NULL);
	pthread_mutex_init(&data->mutex_for_check_last_meal, NULL);
}
