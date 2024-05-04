# include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Use: ./converter [element]" << std::endl;
	else{
		std::string a(argv[1]);
		ScalarConverter::convert(a); 
	}
}