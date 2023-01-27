/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:01:29 by oren              #+#    #+#             */
/*   Updated: 2020/05/08 14:45:02 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		is_char_of_charset(char c, char const *charset)
{
	unsigned int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	size_t		i;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen((char *)s1) - 1;
	while (s1[start] && is_char_of_charset(s1[start], set))
		start++;
	if (start >= end)
		i = 0;
	else
	{
		while (end > start && is_char_of_charset(s1[end], set))
			end--;
		i = end - start + 1;
	}
	return (ft_substr(s1, start, i));
}
