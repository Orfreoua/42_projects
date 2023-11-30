NAME = harl

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address

SRCS_DIR = $(shell find srcs -type d)

INC_DIR	= $(shell find includes -type d)

vpath %.cpp $(foreach dir, $(SRCS_DIR), $(dir):)

SRCS = main.cpp\
		Harl.cpp

OBJ_DIR = objs

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))

IFLAGS =	$(foreach dir, $(INC_DIR), -I$(dir))

# Colors

_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m

all: $(NAME)

show:
				@echo "$(_BLUE)SRCS :\n$(_YELLOW)$(SRCS) $(_WHITE)"
				@echo "$(_BLUE)SRCS_DIR :\n$(_YELLOW)$(SRCS_DIR) $(_WHITE)"
				@echo "$(_BLUE)OBJS :\n$(_YELLOW)$(OBJS) $(_WHITE)"
				@echo "$(_BLUE)OBJ_DIR :\n$(_YELLOW)$(OBJS_DIR) $(_WHITE)"
				@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"

$(OBJ_DIR)/%.o : %.cpp
				@echo -n "Compiling $(_YELLOW)$@$(_WHITE) ... "
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c -D FT=false $<
				@echo "$(_GREEN)DONE$(_WHITE)"

$(NAME):		$(INC_DIR) $(OBJS) Makefile
				@echo -n "-----\nCreating Executable $(_YELLOW)$@$(_WHITE) ... "
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"
exec: $(NAME)
				@echo "Launch Binary File $(_BLUE)$(NAME)$(_WHITE)\n-----"
				@./$(NAME)
				@echo "-----\n$(_BLUE)$(NAME) $(_GREEN)successfully end$(_WHITE)\n-----"

re: fclean all

clean:
				@echo -n "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)" \
				"$(_WHITE) ... "
				@rm -rf $(OBJ_DIR)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:			clean
				@echo -n "Deleting Binaries Files $(_YELLOW)$(NAME)" \
				"$(_WHITE) ... "
				@rm -f $(NAME)
				@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all re clean fclean