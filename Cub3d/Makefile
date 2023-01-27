NAME			= cub3D

SRCS			=	srcs/main.c			\

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
