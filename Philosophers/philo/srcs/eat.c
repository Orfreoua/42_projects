/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:46:54 by orfreoua          #+#    #+#             */
/*   Updated: 2022/06/13 10:46:56 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	unlock_forks(t_data *data, t_philo *philo)
{
	if (philo->index_philo % 2 == 0)
	{
		pthread_mutex_unlock(&data->mutex_fork[philo->fork_r]);
		pthread_mutex_unlock(&data->mutex_fork[philo->fork_l]);
	}
	else
	{
		pthread_mutex_unlock(&data->mutex_fork[philo->fork_l]);
		pthread_mutex_unlock(&data->mutex_fork[philo->fork_r]);
	}
}

void	lock_forks(t_data *data, t_philo *philo)
{
	if (philo->index_philo % 2 == 0)
	{
		pthread_mutex_lock(&data->mutex_fork[philo->fork_r]);
		pthread_mutex_lock(&data->mutex_fork[philo->fork_l]);
	}
	else
	{
		pthread_mutex_lock(&data->mutex_fork[philo->fork_l]);
		pthread_mutex_lock(&data->mutex_fork[philo->fork_r]);
	}
	put_msg(data, philo->index_philo, "has taken a fork", 0);
	put_msg(data, philo->index_philo, "has taken a fork", 0);
}

short	ft_eat(t_data *data, t_philo *philo)
{
	short	index;

	lock_forks(data, philo);
	put_msg(data, philo->index_philo, "is eating", 0);
	philo->nb_meals++;
	pthread_mutex_lock(&data->mutex_for_check_last_meal);
	philo->time_before_last_meal = ft_time();
	pthread_mutex_unlock(&data->mutex_for_check_last_meal);
	index = ft_usleep(data, philo, philo->args.time_to_eat);
	unlock_forks(data, philo);
	return (index);
}
