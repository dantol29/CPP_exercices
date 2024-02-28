#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	std::string text;
	if (argc != 4)
	{
		std::cout << "Only 3 arguments allowed" << std::endl;
		return (1);
	}
	std::ifstream file(argv[1]);
	while (std::getline(file, text))
		std::cout << text << std::endl;
}