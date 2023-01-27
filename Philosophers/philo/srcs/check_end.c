/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:46:38 by orfreoua          #+#    #+#             */
/*   Updated: 2022/06/13 10:46:40 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

short	check_nb_meals(t_data *data, t_philo *philo)
{
	short	i;

	i = 0;
	while (i < philo->args.nb_philo)
	{
		if (data->philo[i].nb_meals == data->args.max_meals)
			i++;
		else
			return (0);
	}
	return (1);
}

short	check_death(t_data *data)
{
	pthread_mutex_lock(&data->mutex_for_check_death);
	if (data->index_if_one_philo_dead)
	{
		pthread_mutex_unlock(&data->mutex_for_check_death);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex_for_check_death);
	return (0);
}

short	check_end(t_data *data, t_philo *philo)
{
	if (check_death(data))
		return (1);
	pthread_mutex_lock(&data->mutex_for_check_nb_meals);
	if (data->args.max_meals != -1)
	{
		if (check_nb_meals(data, philo))
		{
			pthread_mutex_unlock(&data->mutex_for_check_nb_meals);
			return (1);
		}
	}
	pthread_mutex_unlock(&data->mutex_for_check_nb_meals);
	return (0);
}
