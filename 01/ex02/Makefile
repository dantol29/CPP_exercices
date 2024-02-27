COMPILER=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=ptr_ref
SANITAZER=-fsanitize=address
SRC=main.cpp
OBJECTS=$(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
		$(COMPILER) $(FLAGS) $(OBJECTS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re