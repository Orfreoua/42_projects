/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 19:55:21 by akefeder          #+#    #+#             */
/*   Updated: 2022/12/22 21:04:22 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	create_file(char *filename, t_exec *exec)
{
	int	fd;

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH, 0777);
	if (fd == -1)
		return (print_error("file creation failed"));
	exec->hd.cpt_close++;
	return (fd);
}

char	*ft_heredoc_expand(char *str, char **env)
{
	char	**exp;
	int		i;

	if (str && ft_compare_char(str, '$') == FOUND)
	{
		i = 0;
		exp = ft_split_exp(str);
		free(str);
		str = modif_exp(exp, i, env);
		if (str == NULL)
			return (str);
	}
	return (str);
}
