COMPILER=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=serialize
SANITAZER=-fsanitize=address
SRC=main.cpp Serializer.cpp
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