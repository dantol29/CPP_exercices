#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iomanip>
#include <string>
#include <ctime>
#include "Contact.hpp"

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
		int printTable();
		void add(Contact contact);
		void search(int index);
};


#endif