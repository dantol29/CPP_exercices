#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact{
	public:
		void add(std::string first, std::string last, std::string nick,\
		std::string phone, std::string secret);
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
};

#endif