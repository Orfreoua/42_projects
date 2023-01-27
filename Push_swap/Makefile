#run : 
#	gcc -fsanitize=address -g3 -Wall -Wextra -Werror srcs/*.c libft/*.c -o push_swap 

#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := push_swap
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      libft/ft_isdigit.c \
                          libft/ft_putnbr_fd.c \
                          libft/ft_putndl_fd.c \
                          libft/ft_split.c \
                          libft/ft_stdup.c \
                          libft/ft_strlen.c \
                          libft/ft_substr.c \
                          libft/ft_tablen.c \
                          srcs/action_rotation.c \
                          srcs/actions.c \
                          srcs/debug.c \
                          srcs/duplicate_check.c \
                          srcs/free.c \
                          srcs/load_data.c \
                          srcs/little_sort.c \
                          srcs/main.c \
                          srcs/utils.c \
                          srcs/big_sort_first_part.c \
                          srcs/big_sort_second_part.c \
                          srcs/tab_manip.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS}-c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all gcc srcs/*.c libft/*.c -o push_swap

.PHONY:		all clean fclean re


