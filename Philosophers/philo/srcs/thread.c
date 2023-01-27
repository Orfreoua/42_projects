/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:48:38 by orfreoua          #+#    #+#             */
/*   Updated: 2022/06/13 10:48:40 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

short	launch_pthread_join(t_data *data)
{
	short	i;

	i = 0;
	while (i < data->args.nb_philo)
	{
		if (i % 2 == 0)
			pthread_join(data->thread_philo_routine[i], NULL);
		i++;
	}
	i = 0;
	while (i < data->args.nb_philo)
	{
		if (i % 2 != 0)
			pthread_join(data->thread_philo_routine[i], NULL);
		i++;
	}
	return (1);
}

short	load_thread_pair(t_data *data)
{
	short	i;

	i = 0;
	while (i < data->args.nb_philo)
	{
		if (i % 2 == 0)
		{
			if (pthread_create(&data->thread_philo_routine[i], NULL,
					&routine_of_a_philosopher, (void *)&data->philo[i]))
				return (1);
		}
		i++;
	}
	return (0);
}

short	load_thread_unpair(t_data *data)
{
	short	i;

	i = 0;
	while (i < data->args.nb_philo)
	{
		if (i % 2 != 0)
		{
			if (pthread_create(&data->thread_philo_routine[i],
					NULL, &routine_of_a_philosopher,
					(void *)&data->philo[i]))
				return (1);
		}
		i++;
	}
	return (0);
}

short	launch_pthread_create(t_data *data)
{
	if (load_thread_pair(data))
		return (1);
	usleep(10000);
	if (load_thread_unpair(data))
		return (1);
	return (0);
}
