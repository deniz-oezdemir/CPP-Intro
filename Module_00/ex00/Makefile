NAME		=	megaphone
COMPILER	=	c++
FLAGS		=	-Wall -Werror -Wextra -std=c++98
SANITIZER	=	-fsanitize=address

SRCS		=	megaphone.cpp
OBJS		=	$(SRCS:.cpp=.o)

$(NAME):		$(OBJS)
				$(COMPILER) $(FLAGS) $(OBJS) $(SANITIZER) -o $(NAME)

all:			$(NAME)

clean:
				@rm -f $(OBJS)

fclean:			clean
				@rm -f $(NAME)

re:				fclean all

.PHONY: all clean fclean re
