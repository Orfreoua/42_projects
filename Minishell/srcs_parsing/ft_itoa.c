/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:57:18 by orfreoua          #+#    #+#             */
/*   Updated: 2022/10/30 20:41:58 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

char	*exception(void)
{
	char	*str;

	str = malloc(2);
	if (!str)
		return (0);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

int	compt_for_malloc(int n)
{
	int	i;

	i = 0;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*strrev(char *str)
{
	int		i;
	int		j;
	char	swap;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	while (i < j)
	{
		swap = str[i];
		str[i] = str[j - 1];
		str[j - 1] = swap;
		i++;
		j--;
	}
	return (str);
}

char	*fill_the_string(unsigned int nb, int n, char *str)
{
	int	i;

	i = 0;
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i++;
	}
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int				i;
	unsigned int	nb;
	char			*str;

	if (n == 0)
		return (exception());
	i = compt_for_malloc(n);
	if (n < 0)
		nb = (unsigned int)(n * -1) + (0 * i++);
	else
		nb = (unsigned int)n;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str = fill_the_string(nb, n, str);
	str = strrev(str);
	return (str);
}
