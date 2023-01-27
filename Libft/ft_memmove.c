/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 11:48:06 by orfreoua          #+#    #+#             */
/*   Updated: 2020/05/06 11:48:20 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t len_copy;
	size_t i;

	if (!src && !dest)
		return (0);
	len_copy = len;
	i = 0;
	if (src < dest)
	{
		while (len_copy)
		{
			len_copy--;
			((char *)dest)[len_copy] = ((char *)src)[len_copy];
		}
	}
	else
	{
		while (i < len)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}
