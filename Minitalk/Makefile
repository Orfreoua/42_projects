SERVER	= server
CLIENT	= client
CC		= gcc
FLAGS	= -Wall -Werror -Wextra

SRCS	=	./srcs/convert_base_for_char.c \
			./srcs/ft_atoi.c \
			./srcs/ft_itoa_base.c \
			./srcs/ft_putnbr.c \
			./srcs/ft_strjoin.c \

OBJS = ${SRCS:.c=.o}

all : $(OBJS) $(SERVER) $(CLIENT)

$(SERVER) : server.o minitalk.h
	@$(CC) server.o $(SRCS) -o $@
	@printf "\e[38;5;46m./$@ successfully build\e[0m\n"

$(CLIENT) : client.o minitalk.h
	@$(CC) client.o $(SRCS) -o $@
	@printf "\e[38;5;46m./$@ successfully build\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -c

clean :
	@rm -f *.o
	@printf "\e[38;5;226m./files.o deleted\e[0m\n"

fclean: clean
	@rm -f $(SERVER) $(CLIENT) $(OBJS)
	@printf "\e[38;5;226m./binaries deleted\e[0m\n"

re: fclean all