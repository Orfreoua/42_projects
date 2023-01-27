/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:19:42 by orfreoua          #+#    #+#             */
/*   Updated: 2022/03/10 20:19:43 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_tab_int_cpy(int *tab, int size)
{
	int	*new;
	int	i;

	new = malloc(sizeof(int) * (size - 1));
	if (!new)
		return (0);
	i = 0;
	while (i < (size - 1))
	{
		new[i] = tab[i + 1];
		i++;
	}
	free(tab);
	tab = NULL;
	return (new);
}

int	*ft_tab_int_join(int *tab, int value, int size)
{
	int	*new;
	int	i;

	new = malloc(sizeof(int) * (size + 1));
	if (!new)
		return (0);
	i = 0;
	new[i] = value;
	while (i < size)
	{
		new[i + 1] = tab[i];
		i++;
	}
	return (new);
}

int	string_to_int(char *str)
{
	int		result;
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

int	*tab_string_to_tab_int(char **tab_str, size_t nb_values)
{
	int	*tab_int;
	int	i;

	tab_int = malloc(sizeof(int) * nb_values);
	if (!tab_int)
		return (0);
	i = 0;
	while (tab_str[i])
	{
		tab_int[i] = string_to_int(tab_str[i]);
		i++;
	}
	return (tab_int);
}

void	copy_stack(int *stack, t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->nb)
	{
		stack[i] = a->tab[i];
		i++;
	}
}
