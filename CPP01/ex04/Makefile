COMPILER=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=file
SANITAZER=-fsanitize=address
SRC=main.cpp
OBJECTS=$(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
		$(COMPILER) $(FLAGS) $(OBJECTS) $(SANITAZER) -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re