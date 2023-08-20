# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 17:21:55 by orfreoua          #+#    #+#              #
#    Updated: 2023/08/20 21:03:02 by orfreoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS		= srcs/ft_draw.c			\
			srcs/ft_keycode.c		\
			srcs/ft_frame.c			\
			srcs/ray_casting/ft_ray_01.c 	\
			srcs/ray_casting/ft_ray_02.c     \
			srcs/ray_casting/ft_direction.c	\
			srcs/ray_casting/se/ft_se.c      \
			srcs/ray_casting/se/ft_se_x.c	\
			srcs/ray_casting/se/ft_se_y.c	\
			srcs/ray_casting/sw/ft_sw.c	\
			srcs/ray_casting/sw/ft_sw_x.c	\
			srcs/ray_casting/sw/ft_sw_y.c	\
			srcs/ray_casting/nw/ft_nw.c	\
			srcs/ray_casting/nw/ft_nw_x.c	\
			srcs/ray_casting/nw/ft_nw_y.c	\
			srcs/ray_casting/ne/ft_ne.c	\
			srcs/ray_casting//ne/ft_ne_x.c	\
			srcs/ray_casting//ne/ft_ne_y.c   \
			srcs/ray_casting/ft_texture.c	\
			srcs/memory/ft_memory.c		\
			srcs/memory/ft_error.c		\
			srcs/menu.c\
			srcs/minimap.c

DIR_MLX		= ./mlx_linux/
OBJ_DIR		= obj/

OBJS		= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

MAIN		= srcs/main.c
MAIN_BONUS	= srcs/main_bonus.c

OBJ_M		= $(addprefix $(OBJ_DIR), $(MAIN:.c=.o))
OBJ_M_BONUS	= $(addprefix $(OBJ_DIR), $(MAIN_BONUS:.c=.o))

CC			= gcc
CFLAGS		= -g -Wall -Wextra -Werror -I includes.
LIBS		= -L ./mlx_linux/ -lmlx -lXext -lX11 -lm
RM			= rm -f
NAME		= cub3D

all: $(NAME)

$(NAME): $(OBJS) $(OBJ_M)
	make -C $(DIR_MLX)
	${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(OBJ_M) $(LIBS)

bonus: $(OBJS) $(OBJ_M_BONUS)
	make -C $(DIR_MLX)
	${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(OBJ_M_BONUS) $(LIBS)

$(OBJ_DIR)%.o: %.c
	mkdir -p $(dir $@)
	${CC} $(CFLAGS) -c $< -o $@

clean:
	make -C $(DIR_MLX) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re bonus