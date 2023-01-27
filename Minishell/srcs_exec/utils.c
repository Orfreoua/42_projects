/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:57:08 by orfreoua          #+#    #+#             */
/*   Updated: 2022/12/09 14:57:12 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	replace_string_on_tab(char **t, int i, char *s)
{
	char	*swp;

	swp = t[i];
	t[i] = ft_strdup(s);
	free(swp);
}

void	close_and_wait(t_exec *exec, int nb_pipe)
{
	(void)nb_pipe;
	if (exec->pipe.fd_pipe[0] > 0)
		close(exec->pipe.fd_pipe[0]);
	if (exec->pipe.fd_pipe[1] > 0)
		close(exec->pipe.fd_pipe[1]);
}

int	count_nb_pipe(t_data *data)
{
	t_data	*slot;
	int		nb_pipe;

	slot = data;
	nb_pipe = 0;
	while (slot != NULL)
	{
		if (slot->token == PIPE)
			nb_pipe++;
		slot = slot->suiv;
	}
	return (nb_pipe);
}

int	find_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

t_data	*pass_hold_pipe(t_data *data, int cpt_pipe)
{
	t_data	*slot;
	int		i;

	slot = data;
	i = 0;
	while (slot != NULL && i < cpt_pipe)
	{
		if (slot->token == PIPE)
			i++;
		slot = slot->suiv;
	}
	if (slot && slot->token == PIPE)
	{
		if (slot->suiv)
			slot = slot->suiv;
	}
	return (slot);
}
