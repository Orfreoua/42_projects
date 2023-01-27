/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 17:14:43 by orfreoua          #+#    #+#             */
/*   Updated: 2020/05/09 15:28:38 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (s == 0)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free_split(char **a)
{
	size_t i;

	i = 0;
	if (a)
	{
		while (a[i])
		{
			free(a[i]);
			i++;
		}
		free(a);
	}
	return (NULL);
}

char		**ft_split(char const *s, char c)
{
	char	**a;
	size_t	i;
	size_t	k;
	size_t	start;

	i = 0;
	k = 0;
	a = NULL;
	if (s == 0 || !(a = malloc(sizeof(char *) * (count(s, c) + 1))))
		return (ft_free_split(a));
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[start] != '\0' && !(a[k++] = ft_substr(s, start, i - start)))
			return (ft_free_split(a));
	}
	a[k] = NULL;
	return (a);
}
