NAME =		phonebook

SRCS	=	book.cpp\
			contact.cpp\
			utils.cpp\
			table.cpp\
			main.cpp

OBJS	= $(SRCS:%.cpp=$(BIN)/%.o)

DEP = $(OBJS:%.o=%.d)

BIN		= ./bin

CXX	= clang++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f

all: $(NAME)

$(NAME):	$(OBJS)
			@$(CXX) $(CXXFLAGS) $^ -o $@
-include $(DEP)

$(BIN)/%.o:		%.cpp
	@mkdir -p $(@D)
	@$(CXX) $(CXXFLAGS) -MMD -o $@ -c $<

clean:
	@$(RM) $(BIN)/$(OBJS)

fclean:	clean
	@$(RM) $(NAME)
	@rm -r $(BIN)

re:	fclean $(NAME)

.PHONY: all clean fclean re