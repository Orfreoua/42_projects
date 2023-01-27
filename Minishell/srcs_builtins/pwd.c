/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:17:55 by orfreoua          #+#    #+#             */
/*   Updated: 2022/09/17 23:17:56 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*fill_pwd(void)
{
	char	*s;

	if (access(".", F_OK))
	{
		print_error("bad path");
		return (0);
	}
	s = getcwd(NULL, 0);
	return (s);
}

void	builtin_pwd(void)
{
	char	*buf;

	buf = fill_pwd();
	if (buf)
	{
		write(1, buf, ft_strlen(buf));
		write(1, "\n", 1);
		free_string(buf);
	}
}
