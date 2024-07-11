NAME		=	zombies
CXX			=	c++
FLAGS		=	-Wall -Werror -Wextra -std=c++98 -pedantic

SRCS		=	main.cpp Zombie.cpp zombieHorde.cpp
OBJS		=	$(SRCS:.cpp=.o)

SANITIZER	=	-fsanitize=address

$(NAME):		$(OBJS)
				$(CXX) $(FLAGS) $(OBJS) $(SANITIZER) -o $(NAME)

%.o: %.cpp
				$(CXX) $(FLAGS) -c $< -o $@

all:			$(NAME)

clean:
				@rm -f $(OBJS)

fclean:			clean
				@rm -f $(NAME)

re:				fclean all

.PHONY: all clean fclean re
