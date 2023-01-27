/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:18:38 by orfreoua          #+#    #+#             */
/*   Updated: 2022/03/10 20:18:39 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_broken_chain(char **chain, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		free(chain[i]);
		i++;
	}
	free (chain);
}

void	free_tab_two_d(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

void	free_tab_integer(int *tab)
{
	free(tab);
	tab = NULL;
}

void	free_all(t_data *data)
{
	free_tab_integer(data->a.tab);
	free_tab_integer(data->b.tab);
	if (data->orange.nb)
		free_tab_integer(data->orange.tab);
}
