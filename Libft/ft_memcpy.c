/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 18:08:58 by oren              #+#    #+#             */
/*   Updated: 2020/05/09 09:35:04 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*x;
	unsigned char		*y;
	size_t				i;

	if (!src && !dest)
		return (0);
	x = (unsigned char *)src;
	y = dest;
	i = 0;
	while (i < n)
	{
		*y = *x;
		y++;
		x++;
		i++;
	}
	return (dest);
}
