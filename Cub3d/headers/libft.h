/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:57:51 by orfreoua          #+#    #+#             */
/*   Updated: 2023/02/06 19:35:23 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "cub3d.h"

void	ft_putstr_fd(int fd, char *s);
int		ft_strlen(char *str);
char	*ft_substr(char *s, int x, int y);
char	*ft_strjoin(char const *s1, char const *s2, int index_free);
char	*ft_strdup(const char *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
int		get_next_line(int fd, char **line);

#endif