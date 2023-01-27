/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:49:13 by orfreoua          #+#    #+#             */
/*   Updated: 2022/06/13 10:49:14 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	initialization_philos(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->args.nb_philo)
	{
		data->philo[i].fork_l = i;
		if (i == 0)
			data->philo[i].fork_r = data->args.nb_philo - 1;
		else
			data->philo[i].fork_r = i - 1;
		data->philo[i].args.nb_philo = data->args.nb_philo;
		data->philo[i].args.time_to_die = data->args.time_to_die;
		data->philo[i].args.time_to_eat = data->args.time_to_eat;
		data->philo[i].args.time_to_sleep = data->args.time_to_sleep;
		data->philo[i].args.max_meals = data->args.max_meals;
		data->philo[i].index_philo = i;
		data->philo[i].data = (void *)data;
		data->philo[i].time_start = ft_time();
		data->philo[i].time_before_last_meal = 0;
		data->philo[i].nb_meals = 0;
		i++;
	}
}
