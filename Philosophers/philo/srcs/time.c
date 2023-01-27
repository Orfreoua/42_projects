/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:51:04 by orfreoua          #+#    #+#             */
/*   Updated: 2022/06/13 10:51:06 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

short	ft_usleep(t_data *data, t_philo *philo, int time)
{
	int	time_cpt;

	time_cpt = ft_time();
	while (!check_end(data, philo) && (int)(ft_time() - time_cpt) < time)
		usleep(100);
	return (0);
}

long	current_time(long time_start)
{
	return (ft_time() - time_start);
}

long	ft_time(void)
{
	struct timeval	tv;
	long			ret;

	gettimeofday(&tv, (void *)0);
	ret = tv.tv_sec * 1000;
	ret += tv.tv_usec / 1000;
	return (ret);
}
