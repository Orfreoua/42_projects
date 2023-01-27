/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base_for_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:57:51 by orfreoua          #+#    #+#             */
/*   Updated: 2021/11/02 11:44:16 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_sqrt(int nb, int sqrt)
{
	int	i;
	int	result;

	i = 1;
	result = 1;
	while (i < sqrt)
	{
		result *= nb;
		i++;
	}
	return (result);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	convert_base_two(char *nb_b_two)
{
	int	nb;
	int	len;
	int	i;

	nb = 0;
	len = ft_strlen(nb_b_two);
	len = ft_sqrt(2, len);
	i = 0;
	while (nb_b_two[i])
	{
		if (nb_b_two[i] == '1')
			nb += len;
		len /= 2;
		i++;
	}
	return (nb);
}
