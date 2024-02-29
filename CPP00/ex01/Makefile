COMPILER=c++
FLAGS=-Wall -Wextra -Werror -std=c++98
NAME=phonebook
SRC=main.cpp PhoneBook.cpp Contact.cpp
SANITAZER=-fsanitize=address
OBJECTS=$(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
		$(COMPILER) $(FLAGS) $(OBJECTS) $(SANITAZER) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re