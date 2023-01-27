/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 10:55:13 by orfreoua          #+#    #+#             */
/*   Updated: 2022/06/13 10:55:14 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include	<stdlib.h>
# include	<stdio.h>
# include	<unistd.h>
# include	<sys/time.h>
# include	<pthread.h>

# define RED	"\033[00;5;31m"
# define NORMAL	"\033[00m"

typedef struct args
{
	short			nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
}	t_args;

typedef struct philo
{
	short			fork_l;
	short			fork_r;
	short			index_philo;
	void			*data;
	t_args			args;
	long			time_start;
	long			time_before_last_meal;
	int				nb_meals;
}	t_philo;

typedef struct s_data
{
	t_philo			philo[200];
	pthread_t		thread_philo_routine[200];
	pthread_mutex_t	mutex_fork[200];
	t_args			args;
	short			index_if_one_philo_dead;
	pthread_mutex_t	mutex_for_write;
	pthread_mutex_t	mutex_for_check_fork;
	pthread_mutex_t	mutex_for_check_death;
	pthread_mutex_t	mutex_for_check_nb_meals;
	pthread_mutex_t	mutex_for_check_last_meal;
}	t_data;

short	load_arg(t_args *args, int argc, char **argv);
long	ft_time(void);
long	current_time(long time_start);
short	ft_usleep(t_data *data, t_philo *philo, int time);
void	launch_pthread_mutex_init(t_data *data);
void	destroy_mutex_philo(t_data *data);
short	launch_pthread_create(t_data *data);
short	launch_pthread_join(t_data *data);
void	*routine_of_a_philosopher(void *arg);
void	put_msg(t_data *data, int index_philo, char *msg, short died);
short	ft_eat(t_data *data, t_philo *philo);
short	ft_sleep(t_data *data, t_philo *philo);
short	check_end(t_data *data, t_philo *philo);
short	check_death(t_data *data);
short	check_nb_meals(t_data *data, t_philo *philo);
short	check_death_of_philo(t_data *data, t_philo *philo);
void	initialization_philos(t_data *data);
short	check_args(int argc, char **argv, t_data *data);
short	one_philo_dead(t_data *data, short nb_philo);
#endif
