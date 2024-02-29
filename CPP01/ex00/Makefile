COMPILER=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=zombie
SANITAZER=-fsanitize=address
SRC=main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJECTS=$(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
		$(COMPILER) $(FLAGS) $(OBJECTS) $(SANITAZER) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re