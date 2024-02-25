#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

class Contact{
	public:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
};

class PhoneBook{
	private:
		std::string firstName[9];
		std::string lastName[9];
		std::string nickname[9];
		std::string phoneNumber[9];
		std::string darkestSecret[9];
		std::time_t birthday[9];
		int findOldestContact()
		{
			int oldestIndex = 0;

			for (int i = 0; i < 8; ++i)
				if (std::difftime(birthday[oldestIndex], birthday[i]) > 0)
					oldestIndex = i;
			return (oldestIndex);
		}
	public:
		int printTable()
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
			void add(Contact contact){
				for (int i = 0; i < 9; ++i)
				{
					if (i == 8 || firstName[i].empty())
					{
						if (contact.firstName.empty() || contact.lastName.empty() ||\
						contact.nickname.empty() || contact.phoneNumber.empty() || contact.darkestSecret.empty())
						{
							std::cout << "A contact cannot have empty fields" << '\n';
							break ;
						}
						if (i == 8)
							i = findOldestContact();
						firstName[i] = contact.firstName;
						lastName[i] = contact.lastName;
						nickname[i] = contact.nickname;
						phoneNumber[i] = contact.phoneNumber;
						darkestSecret[i] = contact.darkestSecret;
						birthday[i] = std::time(nullptr);
						std::cout << "The contact was succesfully added" << '\n';
						break ;
					}
				}
			}
			void search(int index){
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
};


#endif