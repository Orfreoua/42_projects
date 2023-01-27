/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:17:19 by orfreoua          #+#    #+#             */
/*   Updated: 2022/09/17 23:17:20 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*get_home_path(char **usenv)
{
	int	i;

	i = 0;
	while (usenv[i] && ft_strncmp(usenv[i], "HOME=", 5))
		i++;
	if (usenv[i])
	{
		return (usenv[i] + 5);
	}
	return (0);
}

void	builtin_cd(char *s, t_exec *exec)
{
	s[ft_strlen(s) - 1] = 0;
	if (chdir(s + 3) == -1)
	{
		if (!s[3])
			chdir(get_home_path(exec->env));
		else
		{
			ft_putstr_fd(STDERR_FILENO, "minishell: cd: ");
			ft_putstr_fd(STDERR_FILENO, (s + 3));
			ft_putstr_fd(STDERR_FILENO, ": No such file or directory\n");
			g_exit_ret = 1;
		}
	}
}
