/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_expand_tool.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akefeder <akefeder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:32:18 by akefeder          #+#    #+#             */
/*   Updated: 2022/12/10 21:12:23 by akefeder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parsing.h"

void	ft_split_space(t_data *data)
{
	char	*src;
	t_data	*slot;
	int		i;

	src = data->str;
	i = 0;
	slot = data->suiv;
	data->str = ft_strcopy_char(src, ' ');
	while (src[i] != ' ')
		i++;
	while (src[i] == ' ')
		i++;
	data->suiv = add_l_arg();
	data->suiv->str = ft_strcopy_int(src, &i);
	if (data->follow == 1)
	{
		data->follow = 0;
		data->suiv->follow = 1;
	}
	data->suiv->suiv = slot;
	free(src);
}

char	*ft_strijoin(char *beg, char *end)
{
	char	*ret;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(beg) + ft_strlen(end);
	ret = malloc((len + 1) * sizeof(char));
	i = 0;
	while (beg && beg[i] != '\0')
	{
		ret[i] = beg[i];
		i++;
	}
	j = 0;
	while (end && end[j] != '\0')
	{
		ret[i] = end[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}

char	ft_last_char(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		i++;
	}
	return (c);
}

int	ft_fuse(t_data *slot, t_data *suiv)
{
	if (slot->token == DEFAULT && slot->str[0] == '$')
	{
		if (suiv->token == S_QUOTE || suiv->token == D_QUOTE)
		{
			slot->token = suiv->token;
			free(slot->str);
			slot->str = suiv->str;
			suiv->str = NULL;
			return (ERROR);
		}
	}
	else if (ft_last_char(suiv->str) == '$'
		&& !(suiv->token == S_QUOTE || suiv->token == D_QUOTE))
	{
		return (ERROR);
	}
	return (OK);
}

void	ft_join_arg(t_data *data)
{
	t_data	*slot;
	t_data	*save;
	char	*str;

	slot = data;
	save = NULL;
	while (slot != NULL)
	{
		while (slot->follow == 1)
		{
			str = slot->str;
			if (ft_fuse(slot, slot->suiv) == OK)
			{
				slot->str = ft_strijoin(slot->str, slot->suiv->str);
				free(str);
			}
			save = slot->suiv->suiv;
			slot->follow = slot->suiv->follow;
			del_l_arg(slot->suiv);
			slot->suiv = save;
		}
		slot = slot->suiv;
	}
}
