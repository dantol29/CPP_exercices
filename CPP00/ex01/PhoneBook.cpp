#include "PhoneBook.hpp"

int PhoneBook::findOldestContact() const{
	int oldestIndex = 0;

	for (int i = 0; i < 8; ++i)
		if (std::difftime(birthday[oldestIndex], birthday[i]) > 0)
			oldestIndex = i;
	return (oldestIndex);
}

int PhoneBook::printTable() const{
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

void PhoneBook::search(int index) const {
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

void PhoneBook::add(Contact contact) {
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