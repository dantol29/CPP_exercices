#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>
#include <limits>

#define RED_TEXT "\033[1;31m"
#define WHITE_TEXT "\033[1;37m"
#define BLUE_TEXT "\033[1;34m"
#define RESET_COLOR "\033[0m"

int PhoneBook::printTable()
{
	int i = 0;
	if (firstName[i].empty())
	{
		std::cout << "No contacts in the book" << '\n';
		return (1);
	}
	std::cout << "\n\n\n\n";
	std::cout << "---------------------------------------------" << '\n';
	std::cout << '|' << std::setw(10) << "Index" << '|';
	std::cout << std::setw(10) << "First name" << '|';
	std::cout << std::setw(10) << "Last name" << '|';
	std::cout << std::setw(10) << "Nickname" << '|' << '\n';
	std::cout << "---------------------------------------------" << '\n';
	while (!firstName[i].empty() && i < 8)
	{
		std::cout << '|' << std::setw(10) << i + 1 << '|';
		if (firstName[i].length() > 10)
			std::cout << std::setw(10) << firstName[i].substr(0, 9) + "." << '|';
		else
			std::cout << std::setw(10) << firstName[i] << '|';
		if (lastName[i].length() > 10)
			std::cout << std::setw(10) << lastName[i].substr(0, 9) + "." << '|';
		else
			std::cout << std::setw(10) << lastName[i] << '|';
		if (nickname[i].length() > 10)
			std::cout << std::setw(10) << nickname[i].substr(0, 9) + "." << '|' << '\n';
		else
			std::cout << std::setw(10) << nickname[i] << '|' << '\n';
		std::cout << "---------------------------------------------" << '\n';
		i++;
	}
	std::cout << "\n\n\n\n";
	return (0);
}

void PhoneBook::search(int index)
{
	if (firstName[index - 1].empty())
	{
		std::cout << "Contact with index " << index << " does not exist" << '\n';
		return ;
	}
	std::cout << "\n\n";
	std::cout << "First name: " << firstName[index - 1] << '\n';
	std::cout << "Last name: " << lastName[index - 1] << '\n';
	std::cout << "Nickname: " << nickname[index - 1] << '\n';
	std::cout << "Phone number: " << phoneNumber[index - 1] << '\n';
	std::cout << "Darkest secret: " << darkestSecret[index - 1] << '\n'; 
	std::cout << "\n\n";
}

void PhoneBook::add(Contact contact)
{
	for (int i = 0; i < 9; ++i)
	{
		if (i == 8 || firstName[i].empty())
		{
			if (contact.getFirstName().empty() || contact.getLastName().empty() ||\
			contact.getNickname().empty() || contact.getPhoneNumber().empty() || contact.getDarkestSecret().empty())
			{
				std::cout << "A contact cannot have empty fields" << '\n';
				break ;
			}
			if (i == 8)
				i = findOldestContact();
			firstName[i] = contact.getFirstName();
			lastName[i] = contact.getLastName();
			nickname[i] = contact.getNickname();
			phoneNumber[i] = contact.getPhoneNumber();
			darkestSecret[i] = contact.getDarkestSecret();
			birthday[i] = std::time(NULL);
			std::cout << "The contact was succesfully added" << '\n';
			break ;
		}
	}
}

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