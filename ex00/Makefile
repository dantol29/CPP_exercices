COMPILER=c++
FLAGS=-Wall -Wextra -Werror
NAME=megaphone
SRC=megaphone.cpp
OBJECTS=$(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJECTS)
		$(COMPILER) $(FLAGS) $(OBJECTS)  -o $(NAME)

fclean:
	rm -f $(NAME).exe

re: fclean all

.PHONY: all clean fclean re