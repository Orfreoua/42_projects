/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:04:00 by orfreoua          #+#    #+#             */
/*   Updated: 2022/12/09 15:04:15 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	len_of_new_string(char **tab)
{
	int	spaces;
	int	len;
	int	i;

	spaces = 0;
	len = 0;
	while (tab[spaces])
	{
		i = 0;
		while (tab[spaces][i])
			i++;
		len += i;
		spaces++;
	}
	return (len + spaces + 1);
}

char	*string_bonding(char **tab)
{
	char	*s;
	int		cpt[3];

	s = malloc(sizeof(char) * len_of_new_string(tab));
	if (!s)
		return (NULL);
	cpt[0] = 0;
	cpt[2] = 0;
	while (tab[cpt[0]])
	{
		cpt[1] = 0;
		while (tab[cpt[0]][cpt[1]])
		{
			s[cpt[2]] = tab[cpt[0]][cpt[1]];
			cpt[1]++;
			cpt[2]++;
		}
		s[cpt[2]] = ' ';
		cpt[2]++;
		cpt[0]++;
	}
	s[cpt[2]] = 0;
	return (s);
}

int	is_builtin(char *s)
{
	if (ft_strlen(s))
	{
		if (!strcmp(s, "echo") || !strcmp(s, "cd") || !strcmp(s, "pwd")
			|| !strcmp(s, "export") || !strcmp(s, "unset")
			|| !strcmp(s, "env") || !strcmp(s, "exit"))
			return (1);
	}
	return (0);
}

void	builtins_before_pipe(t_exec *exec, char **cmd, t_data *data)
{
	char	*s;

	s = string_bonding(cmd);
	if (!strcmp(cmd[0], "cd"))
		builtin_cd(s, exec);
	else if (!strcmp(cmd[0], "export"))
		pre_export(exec);
	else if (!strcmp(cmd[0], "unset"))
		pre_unset(exec);
	else if (!strcmp(cmd[0], "exit"))
	{
		free_string(s);
		builtin_exit(exec, data);
		return ;
	}
	free_string(s);
}

void	do_builtin(t_exec *exec, char **cmd)
{
	char	*s;

	(void)exec;
	s = string_bonding(cmd);
	s[ft_strlen(s) - 1] = 0;
	if (!strcmp(cmd[0], "echo"))
		builtin_echo(s);
	else if (!strcmp(cmd[0], "pwd"))
		builtin_pwd();
	else if (!strcmp(cmd[0], "env"))
		builtin_env(exec->env);
	free_string(s);
}
