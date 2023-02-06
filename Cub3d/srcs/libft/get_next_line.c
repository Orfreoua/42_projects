/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:47:03 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/06 19:31:48 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int	get_next_line(int fd, char **line)
{
	int		ret;
	char	buff[2];

	*line = malloc(sizeof(char));
	*line[0] = 0;
	ret = read(fd, buff, 1);
	while (ret > 0 && buff[0] != '\n')
	{
		buff[1] = 0;
		*line = ft_strjoin(*line, buff, 1);
		ret = read(fd, buff, 1);
	}
	if (ret < 1)
		return (0);
	return (1);
}
