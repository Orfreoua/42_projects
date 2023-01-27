/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:06:01 by orfreoua          #+#    #+#             */
/*   Updated: 2021/11/02 10:06:03 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, int signal)
{
	if (signal == 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

void	ft_str_client(int pid, char *msg, int i, int j)
{
	int		ascii_value;
	char	*bin;

	while (msg[i])
	{
		ascii_value = msg[i];
		bin = ft_itoa_base(ascii_value, "01");
		j = -1;
		while (((ft_strlen(bin)) + ++j) < 8)
			send_signal(pid, 0);
		j = 0;
		while (bin[j])
		{
			if (bin[j] == '1')
				send_signal(pid, 1);
			else
				send_signal(pid, 0);
			j++;
		}
		free(bin);
		bin = NULL;
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		ft_str_client(pid, av[2], 0, 0);
	}
	else
		ft_putstr_fd("error: parameters != 3\n", 2);
	return (0);
}
