#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

#define RED_TEXT "\033[1;31m"
#define WHITE_TEXT "\033[1;37m"
#define BLUE_TEXT "\033[1;34m"
#define RESET_COLOR "\033[0m"

void	add(PhoneBook *book)
{
	std::string line[5];
	Contact obj;

	std::cout << "First name: ";
	std::getline(std::cin, line[0], '\n');
	std::cout << "Last name: ";
	std::getline(std::cin, line[1], '\n');
	std::cout << "Nickname: ";
	std::getline(std::cin, line[2], '\n');
	std::cout << "Phone number: ";
	std::getline(std::cin, line[3], '\n');
	std::cout << "Darkest secret: ";
	std::getline(std::cin, line[4], '\n');
	obj.add(line[0], line[1], line[2], line[3], line[4]);
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
		if (std::cin.eof())
    		break;
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
		if (std::cin.eof())
    		break;
		if (line == "ADD")
			add(&book);
		else if (line == "SEARCH")
			search(book);
		else if (line == "EXIT")
			break ;
		else
			std::cout << RED_TEXT << "Unknown command (" << line << ")\n" << RESET_COLOR;
	}
	std::cout << "\nPhoneBook is closed" << '\n'; 
}