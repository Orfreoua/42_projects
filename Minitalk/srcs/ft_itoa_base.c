/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:08:18 by orfreoua          #+#    #+#             */
/*   Updated: 2021/11/02 10:08:20 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	swap;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	while (i < j)
	{
		swap = str[i];
		str[i] = str[j - 1];
		str[j - 1] = swap;
		i++;
		j--;
	}
	return (str);
}

int	find_len_dest(int n, int base)
{
	int	len_dest;

	len_dest = 1;
	if (n < 0)
	{
		len_dest++;
		n = -n;
	}
	while (n > 0)
	{
		n /= base;
		len_dest++;
	}
	return (len_dest);
}

char	*ft_itoa_base(int n, char *base)
{
	char			*dest;
	int				len_dest;
	int				base_integer;
	int				n_cpy;

	base_integer = ft_strlen(base);
	len_dest = find_len_dest(n, base_integer);
	dest = malloc(sizeof(char) * len_dest + 1);
	if (!(dest))
		exit(1);
	len_dest = 0;
	n_cpy = n;
	while (n_cpy > 0)
	{
		dest[len_dest] = base[n_cpy % base_integer];
		n_cpy /= base_integer;
		len_dest++;
	}
	dest[len_dest] = 0;
	dest = ft_strrev(dest);
	return (dest);
}
