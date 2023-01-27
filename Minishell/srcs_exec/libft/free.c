/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:00:27 by orfreoua          #+#    #+#             */
/*   Updated: 2023/01/06 17:43:08 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	free_string(char *s)
{
	free(s);
	s = NULL;
}

int	free_tab_error(char **t, int n)
{
	int	i;

	i = 0;
	while (t && i < n && t[i])
	{
		free(t[i]);
		t[i] = NULL;
		i++;
	}
	free(t);
	t = NULL;
	return (-1);
}

void	free_tab(char **t)
{
	int	i;

	i = 0;
	while (t && t[i])
	{
		free_string(t[i]);
		t[i] = NULL;
		i++;
	}
	free(t);
	t = NULL;
}
