COMPILER=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=bank
SANITAZER=-fsanitize=address
SRC=Account.cpp tests.cpp
OBJECTS=$(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
		$(COMPILER) $(FLAGS) $(OBJECTS) $(SANITAZER) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re