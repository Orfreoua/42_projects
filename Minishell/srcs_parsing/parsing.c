/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:21:15 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/30 20:45:52 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

t_data	*parsing(char *s, char **env)
{
	t_data	*data;

	if (check_space(s) == ERROR)
		return (NULL);
	if (check_error_parse(s) == ERROR)
		return (gest_error(ERR_CHECK, NULL), NULL);
	data = ft_quot_esp_split(s);
	data = ft_pipe_redir(data);
	data = ft_search_expand(data, env);
	data = ft_after_expand(data);
	data = ft_last_error(data);
	if (data == NULL)
		return (NULL);
	return (data);
}

// t_data	*parsing(char *s, char **env)
// {
// 	t_data	*printer;
// 	t_data	*data;
// 	int		i;

// 	////printf(TEST);
// 	if (check_space(s) == ERROR)
// 		return (NULL);
// 	if (check_error_parse(s) == ERROR)
// 		return (gest_error(ERR_CHECK, NULL), NULL);
// 	g_exit_ret = 2;
// 	//printf("parsing : %i\n", g_exit_ret);
// 	data = ft_quot_esp_split(s);
// 	data = ft_pipe_redir(data);
// 	data = ft_search_expand(data, env);
// 	data = ft_after_expand(data);
// 	data = ft_last_error(data);
// 	if (data == NULL)
// 		return (NULL);
// 	////printf(TEST);
// 	printer = data;
// 	i = 0;
// 	while (printer != NULL)
// 	{
// 		//printf("%i : |%s| / Follow : %i / Token : %i\n", i,
// 			printer->str, printer->follow, printer->token);
// 		i++;
// 		printer = printer->suiv;
// 	}
// 	gest_error(END, data);
// 	return (data);
// }