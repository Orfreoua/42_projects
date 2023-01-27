/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 11:48:36 by orfreoua          #+#    #+#             */
/*   Updated: 2020/05/09 14:56:54 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int i;
	unsigned int j;

	if (!*to_find)
		return ((char*)str);
	i = 0;
	while (str[i] != '\0' && (size_t)i < len)
	{
		if (str[i] == to_find[0])
		{
			j = 1;
			while (to_find[j] && str[i + j] == to_find[j] &&
				(size_t)(i + j) < len)
				j++;
			if (to_find[j] == '\0')
				return ((char*)&str[i]);
		}
		i++;
	}
	return (0);
}
