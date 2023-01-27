DOC_PARSING		= srcs_parsing
DOC_EXEC		= srcs_exec
DOC_BUILTINS	= srcs_builtins

MAIN			=	main.c
FILES_PARCING	=	tool.c\
					tool_2.c\
					tool_3.c\
					check_error.c\
					check_error_2.c\
					gest_error.c\
					parsing.c\
					split_arg.c\
					split_env.c\
					strlen.c\
					tool_arg.c\
					esp_quote_tool.c\
					pipe_redir_tool.c\
					token_generator.c\
					expand.c\
					expand_2.c\
					expand_3.c\
					after_expand_tool.c\
					last_error_tool.c
FILES_EXEC		=	signals.c\
					set_env.c\
					error.c\
					utils.c\
					exec.c\
					heredoc_init.c\
					heredoc.c\
					expand_heredoc.c\
					get_cmd.c\
					redir_parsing.c\
					redir.c\
					wait.c\
					path.c\
					free_struct.c\
					libft/ft_substr.c\
					libft/free.c\
					libft/ft_isalpha.c\
					libft/ft_isdigit.c\
					libft/ft_itoa.c\
					libft/ft_putstr_fd.c\
					libft/ft_split.c\
					libft/ft_strdup.c\
					libft/ft_strjoin.c\
					libft/ft_strncmp.c\
					libft/ft_strndup.c\
					libft/ft_putnbr_fd.c\
					libft/ft_putchar_fd.c\
					libft/ft_atoi.c\
					libft/ft_tabdup.c
FILES_BUILTINS	=	builtins.c\
					echo.c\
					pwd.c\
					env.c\
					cd.c\
					export.c\
					unset.c\
					exit.c
SRCS_PARSING	= $(addprefix $(DOC_PARSING)/, $(FILES_PARCING))
SRCS_EXEC		= $(addprefix $(DOC_EXEC)/, $(FILES_EXEC))
SRCS_BUILTINS	= $(addprefix $(DOC_BUILTINS)/, $(FILES_BUILTINS))

INC		= -I includes -I /usr/include

OBJS_P	=	${SRCS_PARSING:.c=.o}
OBJS_E	=	${SRCS_EXEC:.c=.o}
OBJS_B	=	${SRCS_BUILTINS:.c=.o}
OBJS_M	=	${MAIN:.c=.o}
OBJS	= $(OBJS_P) $(OBJS_M) $(OBJS_E) $(OBJS_B)

NAME 	= minishell

CC 		= clang

RM 		= rm -f

#valgrind --trace-children=yes --track-fds=yes -fsanitize=address valgrind --leak-check=full -fsanitize=address
# make re && valgrind --log-file=toto --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=ignore_leak_rl ./minishell
CFLAGS	= -Wall -Wextra -Werror -g3 #-fsanitize=leak -fsanitize=address -fsanitize=undefined

all:		${NAME}

.c.o :
			$(CC) $(CFLAGS) $(INC) -c $< -o $@

${NAME}:	${OBJS} 
			$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME)
			 #mv $(OBJS) build
del_temp:		
		rm -rf temp*

clean:		
			${RM} ${OBJS} ${OBJSBON}

fclean:		clean del_temp
			${RM} ${NAME}

re:			fclean all

run : re fclean

.PHONY:		all clean fclean re bonus
