COMPILER=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=zombie
SANITAZER=-fsanitize=address
SRC=main.cpp newZombie.cpp randomChump.cpp Zombie.cpp
OBJECTS=$(SRC:.cpp=.o)

all: $(NAME)

.cpp.o:
	$(COMPILER) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
		$(COMPILER) $(FLAGS) $(OBJECTS) $(SANITAZER) -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re