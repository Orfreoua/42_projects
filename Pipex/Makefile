NAME	= pipex

CC		= cc

FLAGS	= -Wall -Werror -Wextra

SRCS	=	./ft_fonctions.c \
			./main.c \

OBJS = ${SRCS:.c=.o}

all : $(OBJS) ${NAME}

bonus : $(OBJS)
		cc $(FLAGS) -D BONUS=1 $(SRCS) -o $(NAME)


$(NAME) : pipex.h
	$(CC) $(OBJS) -o $@
	@printf "\e[38;5;46m./$@ successfully build\e[0m\n"

%.o : %.c
	$(CC) $(FLAGS) $< -c


clean :
	rm -f *.o
	@printf "\e[38;5;226m./files.o deleted\e[0m\n"

fclean: clean
	rm -f $(NAME) $(OBJS)
	@printf "\e[38;5;226m./binaries deleted\e[0m\n"

re: fclean all