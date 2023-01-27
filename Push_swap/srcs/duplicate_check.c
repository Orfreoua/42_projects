/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:18:30 by orfreoua          #+#    #+#             */
/*   Updated: 2022/03/10 20:18:32 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pass_sign_and_zeros(char *value)
{
	int	i;

	i = 0;
	if (value[0] == '+'
		|| value[0] == '-')
		i = 1;
	while (value[i] == '0')
		i++;
	return (i);
}

char	fill_sign(char *value)
{
	if (value[0] == '-')
		return ('-');
	return ('+');
}

int	cmp_values(char *value, char **values, int pos)
{
	int		i;
	int		j;
	char	sign_1;
	char	sign_2;

	sign_1 = fill_sign(value);
	while (values[pos])
	{
		i = pass_sign_and_zeros(value);
		sign_2 = fill_sign(values[pos]);
		j = pass_sign_and_zeros(values[pos]);
		while ((value[i] && values[pos][j])
			&& (value[i] == values[pos][j]))
		{
			i++;
			j++;
		}
		if ((!value[i] && !values[pos][j])
			&& (sign_1 == sign_2))
			return (0);
		pos++;
	}
	return (1);
}

int	duplicate_check(char **values)
{
	int	i;

	i = 0;
	while (values[i])
	{
		if (!cmp_values(values[i], values, (i + 1)))
		{
			ft_putndl_fd(values[i], 1);
			return (0);
		}
		i++;
	}
	return (1);
}
