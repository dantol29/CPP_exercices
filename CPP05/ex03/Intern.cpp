#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <map>

Intern::Intern(){
	std::cout << "Default constructor called (Intern)" << std::endl;
}

Intern::~Intern(){
	std::cout << "Destructor called (Intern)" << std::endl;
}

Intern::Intern(const Intern& obj){
	std::cout << "Copy constructor called (Intern)" << std::endl;
	(void)obj;
}

Intern& Intern::operator=(const Intern& obj){
	std::cout << "Assignment operator called (Intern)" << std::endl;
	(void)obj;
	return (*this);
}

AForm* Intern::makeForm(std::string name, std::string target){
	std::map<std::string, AForm*> stringMap;
	stringMap["presidential pardon"] = new PresidentialPardonForm(target);
	stringMap["shrubbery creation"] = new ShrubberyCreationForm(target);
	stringMap["robotomy request"] = new RobotomyRequestForm(target);

	std::map<std::string, AForm*>::iterator it = stringMap.find(name);
    if (it != stringMap.end()){
		for (std::map<std::string, AForm*>::iterator it2 = stringMap.begin(); it2 != stringMap.end(); it2++){
			if (it2->second != it->second)
				delete it2->second;
		}
        return (it->second);
	}
    std::cout << "Form does not exist" << std::endl;
	for (std::map<std::string, AForm*>::iterator it2 = stringMap.begin(); it2 != stringMap.end(); it2++)
			delete it2->second;
	return (NULL);
}