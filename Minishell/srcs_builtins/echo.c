/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:17:25 by orfreoua          #+#    #+#             */
/*   Updated: 2022/09/17 23:17:27 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	pass_next_options(char *new_s, int i)
{
	if (new_s[i] == '-' && new_s[i + 1] == 'n')
	{
		i++;
		while (new_s[i] && new_s[i] == 'n')
			i++;
		if (!new_s[i])
			return (i);
		if (new_s[i] == ' ')
		{
			i++;
			return (i);
		}
	}
	return (0);
}

void	builtin_echo(char *s)
{
	int	i;
	int	j;
	int	nl;

	i = pass_next_options(s, 5);
	nl = 0;
	if (i > 5)
		nl = 1;
	else
		i = 5;
	while (1)
	{
		j = i;
		i = pass_next_options(s, i);
		if (i == 0)
		{
			i = j;
			break ;
		}
	}
	while (s[i])
		write(1, &s[i++], 1);
	if (nl == 0)
		write(1, "\n", 1);
	g_exit_ret = 0;
}
