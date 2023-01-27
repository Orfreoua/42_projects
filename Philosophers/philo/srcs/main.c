/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:48:46 by orfreoua          #+#    #+#             */
/*   Updated: 2022/06/13 10:48:47 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	routine_for_one(t_data *data)
{
	long	time_start;

	time_start = ft_time();
	if (data->args.max_meals != 0)
	{
		printf("%ld, %d %s\n", ft_time() - time_start, 1, "has taken a fork");
		usleep(data->args.time_to_die * 1000);
		printf("%ld, %d %s\n", ft_time() - time_start, 1, "died");
	}
	return (0);
}

short	check_death_of_philo(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->mutex_for_check_last_meal);
	if (ft_time() - philo->time_before_last_meal >= philo->args.time_to_die)
	{
		pthread_mutex_unlock(&data->mutex_for_check_last_meal);
		put_msg(data, philo->index_philo, "died", 1);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex_for_check_last_meal);
	return (0);
}

short	one_philo_dead(t_data *data, short nb_philo)
{
	short	i;

	i = 0;
	while (i < nb_philo)
	{
		if (check_death_of_philo(data, &data->philo[i]))
			return (1);
		i++;
		if (i == nb_philo)
			i = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv, &data))
		return (1);
	if (data.args.nb_philo == 1)
		return (routine_for_one(&data));
	data.index_if_one_philo_dead = 0;
	initialization_philos(&data);
	launch_pthread_mutex_init(&data);
	if (launch_pthread_create(&data))
		return (1);
	usleep(25000);
	if (one_philo_dead(&data, data.args.nb_philo))
	{
		if (launch_pthread_join(&data))
			return (1);
		destroy_mutex_philo(&data);
	}
	return (0);
}
