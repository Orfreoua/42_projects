/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:58:26 by orfreoua          #+#    #+#             */
/*   Updated: 2022/12/09 14:58:29 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	size_t			i;

	dest = malloc(sizeof(char) * (len - start + 1));
	if (!(dest))
		return (0);
	i = 0;
	while (s && s[start] && start < len)
	{
		dest[i] = s[start];
		start++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}
