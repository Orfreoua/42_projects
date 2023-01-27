CC = gcc
NAME = libft.a
SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)
FLAG = -Wall -Wextra -Werror


all: $(NAME)

$(NAME) : $(OBJ)
	ar rc libft.a $(OBJ)
	ranlib libft.a

.c.o:
	$(CC) $(FLAG) -c $< -o $(<:.c=.o)

#$(OBJ): $(SRC)
#	 $(CC) -o $@  -c $<


#bonus:
#	$(CC) $(FLAG) -c ft_lst.c
#	ar rc $(NAME) ft_lst.o

clean: 
	rm -rf *.o

fclean: clean
	rm -rf libft.a
	rm -rf libft.so
re: fclean all
