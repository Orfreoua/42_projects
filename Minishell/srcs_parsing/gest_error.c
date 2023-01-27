/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 11:44:08 by akefeder          #+#    #+#             */
/*   Updated: 2023/01/06 17:13:22 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_parse(t_data *data)
{
	t_data	*tmp;

	tmp = NULL;
	while (data != NULL)
	{
		tmp = data->suiv;
		if (data->str != NULL)
			free(data->str);
		free(data);
		data = tmp;
	}
}

void	gest_error(int code_err, t_data *data)
{
	if (code_err == ERR_CHECK)
		print_error("COMMAND DONT RESPECT THE FORMAT");
	else if (code_err == ERR_SPLIT)
	{
		free_parse(data);
		print_error("PROBLEM WITH COMMAND");
		data = NULL;
	}
	else if (code_err == END)
		free_parse(data);
}
