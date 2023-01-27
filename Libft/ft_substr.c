/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oren <orfreoua@student42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 10:23:12 by oren              #+#    #+#             */
/*   Updated: 2020/05/07 10:39:54 by oren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*dest;

	if (!s)
		return (0);
	if (!(dest = (char*)malloc(len + 1)))
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
