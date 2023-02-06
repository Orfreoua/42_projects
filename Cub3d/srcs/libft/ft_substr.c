/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:57:48 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/06 19:24:55 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char	*ft_substr(char *s, int x, int y)
{
	char	*new_s;
	int		size;
	int		i;

	size = y - x;
	if (size < 0 || (ft_strlen(s) < y))
		return (0);
	new_s = malloc(sizeof(char *) * (size + 1));
	if (!new_s)
		return (0);
	i = 0;
	while ((x + i) < y)
	{
		new_s[i] = s[x + i];
		i++;
	}
	new_s[x + i] = 0;
	return (new_s);
}
