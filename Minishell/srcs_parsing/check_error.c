/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:47:12 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/30 20:41:58 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

int	ft_find_end(char *s, int *i, char c)
{
	int	j;

	j = (*i) + 1;
	while (s[j] != '\0')
	{
		if (s[j] == c)
		{
			(*i) = j;
			return (OK);
		}
		j++;
	}
	return (ERROR);
}

int	ft_test_pipe(char *s, int i)
{
	int	j;

	j = i;
	if (j == 0)
		return (ERROR);
	if (s[j + 1] == '\0')
		return (ERROR);
	if (s[j + 1] == '|')
		return (ERROR);
	j++;
	while (s[j] == ' ')
		j++;
	if (s[j] == '\0')
		return (ERROR);
	return (OK);
}

int	ft_test_redir_l(char *s, int *i)
{
	int	j;

	j = (*i);
	if (s[j + 1] == '\0')
		return (ERROR);
	if (s[j + 1] == '<')
	{
		if (s[j + 2] == '<' || s[j + 2] == '\0')
			return (ERROR);
		(*i) = j + 1;
		j++;
	}
	j++;
	while (s[j] == ' ')
		j++;
	if (s[j] == '\0')
		return (ERROR);
	return (OK);
}

int	ft_test_redir_r(char *s, int *i)
{
	int	j;

	j = (*i);
	if (s[j + 1] == '\0')
		return (ERROR);
	if (s[j + 1] == '>')
	{
		if (s[j + 2] == '>' || s[j + 2] == '\0')
			return (ERROR);
		(*i) = j + 1;
		j++;
	}
	j++;
	while (s[j] == ' ')
		j++;
	if (s[j] == '\0')
		return (ERROR);
	return (OK);
}

int	check_error_parse(char *s)
{
	int	i;
	int	error;

	if (!s)
		return (ERROR);
	i = 0;
	error = 0;
	while (s[i] != '\0' && error == 0)
	{
		if (s[i] == '\'')
			error = ft_find_end(s, &i, '\'');
		else if (s[i] == '\"')
			error = ft_find_end(s, &i, '\"');
		else if (s[i] == '|')
			error = ft_test_pipe(s, i);
		else if (s[i] == '<')
			error = ft_test_redir_l(s, &i);
		else if (s[i] == '>')
			error = ft_test_redir_r(s, &i);
		i++;
	}
	return (error);
}
