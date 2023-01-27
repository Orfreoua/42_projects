/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:20:59 by orfreoua          #+#    #+#             */
/*   Updated: 2022/10/24 17:21:00 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	*ft_strjoin(char const *s1, char const *s2, int index_free)
{
	char	*s3;
	int		size;
	int		ct[2];

	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	s3 = malloc(sizeof(char) * (size + 1));
	if (!s3)
		return (0);
	ct[0] = 0;
	while (s1[ct[0]])
	{
		s3[ct[0]] = s1[ct[0]];
		ct[0]++;
	}
	ct[1] = 0;
	while (s2[ct[1]])
	{
		s3[ct[0] + ct[1]] = s2[ct[1]];
		ct[1]++;
	}
	s3[ct[0] + ct[1]] = '\0';
	if (index_free)
		free((char *)s1);
	return (s3);
}
