COMPILER=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=fixed
SANITAZER=-fsanitize=address
SRC=main.cpp Fixed.cpp Point.cpp bsp.cpp
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