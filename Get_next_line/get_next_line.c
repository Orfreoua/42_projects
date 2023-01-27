/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <orfreoua@sudent.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:24:30 by oren              #+#    #+#             */
/*   Updated: 2020/06/27 14:22:55 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char *s)
{
	free(s);
	s = NULL;
}

size_t	ft_strlen(char *s)
{
	size_t len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

int		get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	static char *extra_char = NULL;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, buf, 0) == -1)
		return (-1);
	while ((is_end(extra_char) == -1) && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		extra_char = ft_strjoin(extra_char, buf);
	}
	if (is_end(extra_char) > -1)
	{
		*line = ft_strndup(extra_char, is_end(extra_char));
		temp = reset_text((is_end(extra_char) + 1), extra_char);
		ft_free(extra_char);
		extra_char = ft_strndup(temp, ft_strlen(temp));
		ft_free(temp);
		return (1);
	}
	*line = ft_strndup(extra_char, ft_strlen(extra_char));
	ft_free(extra_char);
	extra_char = NULL;
	return (0);
}
