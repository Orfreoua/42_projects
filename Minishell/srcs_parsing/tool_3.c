/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 21:11:12 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/30 20:41:58 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

int	ft_num(char c)
{
	if (c > 47 && c < 58)
		return (FOUND);
	return (N_FOUND);
}

int	ft_maj(char c)
{
	if (c > 64 && c < 91)
		return (FOUND);
	return (N_FOUND);
}

int	ft_min(char c)
{
	if (c > 96 && c < 123)
		return (FOUND);
	return (N_FOUND);
}
