#include "Harl.hpp"

int	find(char *str)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++){
		if (levels[i] == str)
			return (i);
	}
	return (-1);
}

void	choose(char *str)
{
	Harl	obj;
	int		index;

	index = find(str);
	switch (index)
	{
		case 0:
			obj.complain("DEBUG");
		case 1:
			obj.complain("INFO");
		case 2:
			obj.complain("WARNING");
		case 3:
			obj.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
		choose(argv[1]);
	return (0);
}