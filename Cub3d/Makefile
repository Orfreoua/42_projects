# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 14:57:57 by orfreoua          #+#    #+#              #
#    Updated: 2023/02/08 18:19:22 by orfreoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= cub3D

SRCS			=	srcs/main.c\
					srcs/utils.c\
					srcs/libft/ft_putstr_fd.c\
					srcs/libft/ft_strlen.c\
					srcs/libft/ft_substr.c\
					srcs/libft/ft_strjoin.c\
					srcs/libft/ft_strdup.c\
					srcs/libft/ft_putnbr_fd.c\
					srcs/libft/ft_putchar_fd.c\
					srcs/libft/get_next_line.c\
					srcs/libft/ft_strncmp.c\
					srcs/parsing/load_file.c\
					srcs/parsing/load_file_utils.c\
					

DIR_MLX			=	./mlx_linux/

OBJS			= $(SRCS:.c=.o)

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -I includes.

LIBS			= -L ./mlx_linux/ -lmlx -lXext -lX11 -lm

RM				= rm -f

all:		${NAME}

.c.o:
				${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:c=o}

$(NAME):	$(OBJS)
				make -C $(DIR_MLX)
				${CC} $(CFLAGS) -o $(NAME) $(SRCS) $(LIBS)

clean:
				make -C $(DIR_MLX) clean
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re: clean all

.PHONY:		all clean fclean re
