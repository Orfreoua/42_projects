NAME		= megaphone

SRCS		= megaphone.cpp

OBJS		= ${SRCS:.cpp=.o}

CPP			= clang++

RM			= rm -rf

CPP_FLAGS	= -std=c++98 -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			${CPP} ${CPP_FLAGS} ${OBJS} -o ${NAME}

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
