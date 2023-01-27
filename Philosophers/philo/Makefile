NAME	= philo

CC		= cc

FLAGS	= -Wall -Werror -Wextra

SRCS	=	./srcs/check_end.c \
			./srcs/display.c \
			./srcs/eat.c\
			./srcs/load_args.c \
			./srcs/load_error.c \
			./srcs/main.c \
			./srcs/mutex.c \
			./srcs/philos_init.c \
			./srcs/routine.c \
			./srcs/sleep.c \
			./srcs/thread.c \
			./srcs/time.c \

OBJS = ${SRCS:.c=.o}

all : $(OBJS) ${NAME}

$(NAME) : philo.h
	@$(CC) $(SRCS) -pthread -o $@
	@printf "\e[38;5;46m./$@ successfully build\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -c

clean :
	@rm -f *.o
	@printf "\e[38;5;226m./files.o deleted\e[0m\n"

fclean: clean
	@rm -f $(NAME) $(OBJS)
	@printf "\e[38;5;226m./binaries deleted\e[0m\n"

re: fclean all
