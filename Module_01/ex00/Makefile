NAME		=	zombies
CXX			=	c++
FLAGS		=	-Wall -Werror -Wextra -std=c++98 -pedantic

SRCS		=	main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJS		=	$(SRCS:.cpp=.o)

SANITAZER	=	-fsanitize=address

$(NAME):		$(OBJS)
				$(CXX) $(FLAGS) $(OBJS) $(SANITAZER) -o $(NAME)

%.o: %.cpp
				$(CXX) $(FLAGS) -c $< -o $@

all:			$(NAME)

clean:
				@rm -f $(OBJS)

fclean:			clean
				@rm -f $(NAME)

re:				fclean all

.PHONY: all clean fclean re
