/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 15:58:20 by orfreoua          #+#    #+#             */
/*   Updated: 2022/10/02 15:58:21 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	*fill_string(char *s, int start, int end)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * (end - start + 1));
	if (!new)
		return (0);
	while (start < end)
	{
		new[i] = s[start];
		start++;
		i++;
	}
	new[i] = 0;
	return (new);
}

char	**fill_tab(char *s, int count, char sep)
{
	char	**tab;
	int		i;
	int		start;
	int		end;

	tab = malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (0);
	end = 0;
	i = 0;
	while (s && s[end] == sep)
			end++;
	while (i < count)
	{
		start = end;
		while (s[end] && s[end] != sep)
			end++;
		tab[i] = fill_string(s, start, end);
		while (s[end] == sep)
			end++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char	**split(char *s, char sep)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] == sep)
			i++;
		if (s[i] && s[i] != sep)
		{
			while (s[i] && s[i] != sep)
				i++;
			count++;
		}
	}
	return (fill_tab(s, count, sep));
}

/*
int main(void)
{
	char **s = split("salut les toto\n", ' ');
	int i = 0;
	while (s[i])
	{
		//printf("%s\n", s[i]);
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}
*/