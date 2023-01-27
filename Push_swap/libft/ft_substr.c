/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:18:08 by orfreoua          #+#    #+#             */
/*   Updated: 2022/03/11 16:18:10 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*dest;

	if (!s)
		return (0);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (0);
	i = 0;
	if (start < ft_strlen((char *)s))
	{
		while (s[start + i] && (size_t)i < len)
		{
			dest[i] = s[start + i];
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
