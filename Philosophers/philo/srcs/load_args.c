/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 09:07:04 by orfreoua          #+#    #+#             */
/*   Updated: 2022/05/14 09:07:06 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

short	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		final;

	i = 0;
	res = 0;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - 48);
	if (str[i] && !ft_isdigit(str[i]))
		return (-1);
	if (res > 2147483647)
		return (-1);
	final = (int)res;
	return (final);
}

short	load_arg(t_args *args, int argc, char **argv)
{
	args->nb_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		args->max_meals = ft_atoi(argv[5]);
		if (args->max_meals == -1)
			return (0);
	}
	else
		args->max_meals = -1;
	if (args->nb_philo == -1 || args->nb_philo > 200
		|| args->time_to_die == -1
		|| args->time_to_eat == -1
		|| args->time_to_sleep == -1)
		return (0);
	return (1);
}
