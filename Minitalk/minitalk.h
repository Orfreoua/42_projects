/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:07:46 by orfreoua          #+#    #+#             */
/*   Updated: 2021/11/02 10:07:53 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_itoa_base(int n, char *base);
int		convert_base_two(char *nb_b_two);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2, size_t j, size_t i);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstr_fd(char const *s, int fd);

#endif
