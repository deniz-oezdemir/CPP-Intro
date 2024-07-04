NAME		=	zombies
COMPILER	=	c++
FLAGS		=	-Wall -Werror -Wextra -std=c++98

SRCS		=	main.cpp Zombie.cpp zombieHorde.cpp
OBJS		=	$(SRCS:.cpp=.o)

SANITAZER=-fsanitize=address

$(NAME):		$(OBJS)
				$(COMPILER) $(FLAGS) $(OBJS) $(SANITAZER) -o $(NAME)

all:			$(NAME)

clean:
				@rm -f $(OBJS)

fclean:			clean
				@rm -f $(NAME)

re:				fclean all

.PHONY: all clean fclean re
