/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esp_quote_tool.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:44:11 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/30 20:41:58 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

int	ft_comp_esp_split(t_data *slot, char src)
{
	if (src == '\'')
	{
		slot->token = S_QUOTE;
		return (1);
	}
	else if (src == '\"')
	{
		slot->token = D_QUOTE;
		return (2);
	}
	else
	{
		return (0);
	}
}

int	ft_quote_case(char *str, char *cpy, int *i, char c)
{
	int	j;

	j = 0;
	while (str[(*i)] != '\0' && str[(*i)] != c)
	{
		cpy[j] = str[(*i)];
		(*i)++;
		j++;
	}
	cpy[j] = '\0';
	(*i)++;
	if (str[(*i)] != ' ' && str[(*i)] != '\0')
		return (FOLLOW);
	else
	{
		return (N_FOLLOW);
	}
}

int	ft_space_case(char *str, char *cpy, int *i, char *c)
{
	int	j;

	j = 0;
	while (str[(*i)] != '\0' && ft_compare(str[(*i)], c) == N_FOUND)
	{
		cpy[j] = str[(*i)];
		(*i)++;
		j++;
	}
	cpy[(j)] = '\0';
	if (str[(*i)] != ' ' && str[(*i)] != '\0')
		return (FOLLOW);
	else
	{
		return (N_FOLLOW);
	}
}

char	*ft_strcopy_esp_split(t_data *slot, char *str, int *i, char *c)
{
	int		choice;
	int		len;
	char	*cpy;

	while (str[(*i)] == ' ')
			(*i)++;
	choice = ft_comp_esp_split(slot, str[(*i)]);
	len = ft_strlen_char_i(str, c[choice], (*i));
	cpy = malloc ((len + 1) * sizeof(char));
	if (str == NULL || cpy == NULL )
		return (NULL);
	if (c[choice] == '\'' || c[choice] == '\"')
	{	
		(*i)++;
		slot->follow = ft_quote_case(str, cpy, i, c[choice]);
	}
	else
	{
		slot->follow = ft_space_case(str, cpy, i, c);
	}
	return (cpy);
}
