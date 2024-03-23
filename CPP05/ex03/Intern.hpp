#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern{
	public:
		Intern();
		~Intern();
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);
		AForm* makeForm(std::string name, std::string target);
};

#endif