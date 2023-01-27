/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:05:54 by orfreoua          #+#    #+#             */
/*   Updated: 2021/11/02 10:05:56 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	f_sig(int sig)
{
	static char	*string;
	char		c;

	if (sig == SIGUSR2)
		string = ft_strjoin(string, "0", 0, 0);
	else if (sig == SIGUSR1)
		string = ft_strjoin(string, "1", 0, 0);
	if (((ft_strlen(string)) == 8))
	{
		c = convert_base_two(string);
		free(string);
		string = NULL;
		ft_putchar(c);
	}
}

int	main(void)
{
	ft_putnbr(getpid());
	ft_putchar('\n');
	signal(SIGUSR2, f_sig);
	signal(SIGUSR1, f_sig);
	while (1)
		pause();
}
