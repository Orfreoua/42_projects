/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:58:34 by orfreoua          #+#    #+#             */
/*   Updated: 2021/11/02 20:58:37 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int	i;

	i = 0;
	while (s && s[i])
		write(fd, &s[i++], 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	*ft_strjoin(char *s1, char *s2, size_t j, size_t i)
{
	char	*dest;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!(s1))
			exit(1);
		s1[0] = 0;
	}
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!(dest))
		exit(1);
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = 0;
	free(s1);
	return (dest);
}
