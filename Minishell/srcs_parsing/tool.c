/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 12:08:02 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/30 20:41:58 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

int	ft_compare(char src, char *cmp)
{
	int	j;

	j = 0;
	while (cmp[j] != '\0')
	{
		if (src == cmp[j])
			return (FOUND);
		j++;
	}
	return (N_FOUND);
}

int	ft_compare_str(char *src, char *cmp)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (ft_compare(src[i], cmp) == FOUND)
			return (FOUND);
		i++;
	}
	return (N_FOUND);
}

int	ft_compare_char(char *src, char cmp)
{
	int	i;

	i = 0;
	if (src)
	{
		while (src[i] != '\0')
		{
			if (src[i] == cmp)
				return (FOUND);
			i++;
		}
	}
	return (N_FOUND);
}
