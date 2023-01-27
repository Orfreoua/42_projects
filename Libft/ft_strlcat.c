/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 16:55:40 by orfreoua          #+#    #+#             */
/*   Updated: 2020/05/06 16:55:42 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int size_src;
	unsigned int size_dest;

	size_src = ft_strlen(src);
	if (size == 0)
		return (size_src);
	size_dest = ft_strlen(dest);
	if (size_dest >= size)
		return (size_src + size);
	i = 0;
	while (((size_dest + i) < (size - 1)) && src[i])
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	dest[size_dest + i] = '\0';
	return (size_dest + size_src);
}
