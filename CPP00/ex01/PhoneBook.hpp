#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>
#include "Contact.hpp"

class PhoneBook{
	public:
		int printTable() const;
		void add(Contact contact);
		void search(int index) const;
	private:
		std::string firstName[9];
		std::string lastName[9];
		std::string nickname[9];
		std::string phoneNumber[9];
		std::string darkestSecret[9];
		std::time_t birthday[9];
		int findOldestContact() const;
};


#endif