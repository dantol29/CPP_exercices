#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkestSecret;
	public:
		void add(std::string first, std::string last, std::string nick,\
		std::string phone, std::string secret)
		{
			firstName = first;
			lastName = last;
			nickname = nick;
			phoneNumber = phone;
			darkestSecret = secret;
		}
		std::string getFirstName(){
			return firstName;
		}
		std::string getLastName(){
			return lastName;
		}
		std::string getNickname(){
			return nickname;
		}
		std::string getPhoneNumber(){
			return phoneNumber;
		}
		std::string getDarkestSecret(){
			return darkestSecret;
		}
};

#endif