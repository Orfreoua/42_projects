/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:51:20 by orfreoua          #+#    #+#             */
/*   Updated: 2022/06/13 10:51:22 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine_of_a_philosopher(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = (t_data *)philo->data;
	pthread_mutex_lock(&data->mutex_for_check_last_meal);
	philo->time_before_last_meal = ft_time();
	pthread_mutex_unlock(&data->mutex_for_check_last_meal);
	while (!check_end(data, philo))
	{
		if (ft_eat(data, philo))
			break ;
		if (ft_sleep(data, philo))
			break ;
		put_msg(data, philo->index_philo, "is thinking", 0);
		usleep(1000);
	}
	return (0);
}
