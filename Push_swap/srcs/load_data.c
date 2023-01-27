/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laod_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:18:50 by orfreoua          #+#    #+#             */
/*   Updated: 2022/03/10 20:18:51 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	string_to_long(char *str)
{
	long	result;
	int		i;
	char	sign;

	i = 0;
	if (str[0] == '-')
		sign = '-';
	else
		sign = '+';
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	result = 0;
	while (str[i])
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	if (sign == '-')
		result *= -1;
	return (result);
}

int	check_values(char **values)
{
	int		i;
	int		j;
	long	value;

	i = 0;
	while (values[i])
	{
		j = 0;
		if (values[i][0] == '+'
				|| values[i][0] == '-')
			j = 1;
		while (values[i][j])
		{
			if (!ft_isdigit(values[i][j]))
				return (0);
			j++;
		}
		value = string_to_long(values[i]);
		if (j > 15)
			return (0);
		if (value > INT_MAX || value < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

char	**fill_values(int ac, char **av)
{
	char	**values;
	int		i;

	if (ac == 2)
		values = ft_split(av[1], ' ');
	else
	{
		values = malloc(sizeof(char *) * ac);
		if (!values)
			return (0);
		i = 0;
		while ((i + 1) < ac)
		{
			values[i] = ft_strdup(av[i + 1]);
			if (!values[i])
			{
				free_broken_chain(values, i);
				return (0);
			}
			i++;
		}
		values[i] = 0;
	}
	return (values);
}

int	load_data(t_data *data, int ac, char **av)
{
	char	**values;

	values = fill_values(ac, av);
	if (!values)
		return (error(0, "Error: Malloc failed (1)", 1));
	if (!check_values(values))
	{
		free_tab_two_d(values);
		return (error(0, "Error", 1));
	}
	if (!duplicate_check(values))
	{
		free_tab_two_d(values);
		return (error(0, "Error", 1));
	}
	data->a.nb = ft_tablen(values);
	data->a.tab = tab_string_to_tab_int(values, data->a.nb);
	if (!data->a.tab)
	{
		free_tab_two_d(values);
		return (error(0, "Error: Malloc failed (2)", 1));
	}
	free_tab_two_d(values);
	return (1);
}
