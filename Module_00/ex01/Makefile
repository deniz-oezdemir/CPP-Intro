NAME		=	phonebook
COMPILER	=	c++
FLAGS		=	-Wall -Werror -Wextra -std=c++98

SRCS		=	phonebook.cpp contact.cpp main.cpp
OBJS		=	$(SRCS:.cpp=.o)

$(NAME):		$(OBJS)
				$(COMPILER) $(FLAGS) $(OBJS) -o $(NAME)

all:			$(NAME)

clean:
				@rm -f $(OBJS)

fclean:			clean
				@rm -f $(NAME)

re:				fclean all

.PHONY: all clean fclean re
