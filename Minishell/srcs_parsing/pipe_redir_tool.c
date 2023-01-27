/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_redir_tool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:44:43 by akefeder          #+#    #+#             */
/*   Updated: 2022/10/30 20:41:58 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

void	ft_split_l_redir(t_data *data, char *src, int *i)
{
	data->str = ft_strcopy_char(src, '<');
	if (src[(*i) + 1] == '<')
	{
		(*i)++;
		data->suiv = add_d_l_redir_token();
	}
	else
	{
		data->suiv = add_s_l_redir_token();
	}
	(*i)++;
	if (data->str != NULL && data->suiv != NULL)
	{
		data->suiv->suiv = add_l_arg();
		data->suiv->suiv->str = ft_strcopy_int(src, i);
	}
	if (data->str == NULL || data->suiv == NULL
		|| data->suiv->suiv == NULL || data->suiv->suiv->str == NULL)
	{
		free_parse(data);
		data = NULL;
	}
}

void	ft_split_r_redir(t_data *data, char *src, int *i)
{
	data->str = ft_strcopy_char(src, '>');
	if (src && src[(*i) + 1] == '>')
	{
		(*i)++;
		data->suiv = add_d_r_redir_token();
	}
	else
	{
		data->suiv = add_s_r_redir_token();
	}
	(*i)++;
	if (data->str != NULL && data->suiv != NULL)
	{
		data->suiv->suiv = add_l_arg();
		data->suiv->suiv->str = ft_strcopy_int(src, i);
	}
	if (data->str == NULL || data->suiv == NULL
		|| data->suiv->suiv == NULL || data->suiv->suiv->str == NULL)
	{
		free_parse(data);
		data = NULL;
	}
}

void	ft_split_pipe_redir(t_data *data, char *src, int *i)
{
	data->str = ft_strcopy_char(src, '|');
	data->suiv = add_pipe_token();
	(*i)++;
	if (data->str != NULL && data->suiv != NULL)
	{
		data->suiv->suiv = add_l_arg();
		data->suiv->suiv->str = ft_strcopy_int(src, i);
	}
	if (data->str == NULL || data->suiv == NULL
		|| data->suiv->suiv == NULL || data->suiv->suiv->str == NULL)
	{
		free_parse(data);
		data = NULL;
	}
}

void	ft_error_rp_split(t_data *data, t_data *save)
{
	if (data && data->suiv != NULL && data->suiv->suiv != NULL)
	{
		data->suiv->suiv->suiv = save;
		if (data->follow == 1)
		{
			data->follow = 0;
			data->suiv->suiv->follow = 1;
		}
	}
	else
		free_parse(save);
}

void	ft_select_split(t_data *data)
{
	char	*src;
	t_data	*save;
	int		i;

	src = data->str;
	save = data->suiv;
	i = 0;
	while (src && src[i] != '\0')
	{
		if (src[i] == '<')
			ft_split_l_redir(data, src, &i);
		else if (src[i] == '>')
			ft_split_r_redir(data, src, &i);
		else if (src[i] == '|')
			ft_split_pipe_redir(data, src, &i);
		if (src[i] != '\0')
			i++;
	}
	ft_error_rp_split(data, save);
	free(src);
}
