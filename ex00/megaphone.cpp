#include <iostream>
#include <string>

class Megaphone{
	public:
		void Message(std::string message){
			for (size_t i = 0; i < message.length(); ++i)
				std::cout << (char)std::toupper(message[i]);
			std::cout << '\n';
		}
		void Error(){
			std::cout << "* LOUD AND UNBEAREABLE FEEDBACK NOISE *" << '\n';
		}
};

int	main(int argc, char **argv)
{
	Megaphone obj;
	if (argc == 1)
		obj.Error();
	else if (argc == 2)
		obj.Message(argv[1]);
	else if (argc > 2)
		std::cout <<"* ERROR ERROR *" << '\n';
	return (0);
}