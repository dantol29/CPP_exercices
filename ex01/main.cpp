#include "PhoneBook.hpp"
#include <string>
#include <iostream>

#define RED_TEXT "\033[1;31m"
#define WHITE_TEXT "\033[1;37m"
#define BLUE_TEXT "\033[1;34m"
#define RESET_COLOR "\033[0m"

void	add(PhoneBook *book)
{
	std::string line;
	Contact obj;

	std::cout << "First name: ";
	std::getline(std::cin, obj.firstName, '\n');
	std::cout << "Last name: ";
	std::getline(std::cin, obj.lastName, '\n');
	std::cout << "Nickname: ";
	std::getline(std::cin, obj.nickname, '\n');
	std::cout << "Phone number: ";
	std::getline(std::cin, obj.phoneNumber, '\n');
	std::cout << "Darkest secret: ";
	std::getline(std::cin, obj.darkestSecret, '\n');
	book->add(obj);
}

void search(PhoneBook book)
{
	std::string	line;
	int			index;

	if (book.printTable() == 1)
		return ;
	while (1)
	{
		std::cout << "Enter the index to view the contact (Q to exit): ";
		std::getline(std::cin, line, '\n');
		index = atoi(line.c_str());
		if (line == "Q")
			return ;
		if (!(index > 0 && index < 9))
		{
			std::cout << "Contact with index " << line << " does not exist" << '\n';
			continue ;
		}
		book.search(index);
	}
}

int main()
{
	PhoneBook book;
	std::string line;

	std::cout << WHITE_TEXT <<"PhoneBook 1981 (42 CORPORATION)" << '\n' << RESET_COLOR;
	std::cout << WHITE_TEXT <<"Commands: ADD, SEARCH, EXIT" << '\n' << RESET_COLOR;
	while (1)
	{
		std::cout << BLUE_TEXT << "PhoneBook: " << RESET_COLOR;
		std::getline(std::cin, line, '\n');
		if (line == "ADD")
			add(&book);
		else if (line == "SEARCH")
			search(book);
		else if (line == "EXIT")
			break ;
		else
			std::cout << RED_TEXT << "Unknown command (" << line << ")\n" << RESET_COLOR;
	}
	std::cout << "PhoneBook is closed" << '\n'; 
}