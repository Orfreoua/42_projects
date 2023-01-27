/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:17:21 by orfreoua          #+#    #+#             */
/*   Updated: 2022/03/11 16:17:22 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

char	**ft_free_split(char **a)
{
	size_t	i;

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

char	**ft_split(char const *s, char c)
{
	char	**a;
	size_t	i;
	size_t	k;
	size_t	start;

	i = 0;
	k = 0;
	a = NULL;
	a = malloc(sizeof(char *) * (count(s, c) + 1));
	if (s == 0 || !a)
		return (ft_free_split(a));
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		a[k] = ft_substr(s, start, i - start);
		if (s[start] && !(a[k]))
			return (ft_free_split(a));
		k++;
	}
	a[k] = NULL;
	return (a);
}
