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

struct FormLookup {
    const char* name;
    AForm* form;
};

AForm* Intern::makeForm(std::string name, std::string target){
	unsigned int size = 3;
	AForm* foundForm = NULL;
	FormLookup a[] = {
	{"presidential pardon", new PresidentialPardonForm(target)}, 
	{"shrubbery creation", new ShrubberyCreationForm(target)},
	{"robotomy request", new RobotomyRequestForm(target)}
	};

    for (unsigned int i = 0; i < size; ++i){
		if (name == a[i].name){
			foundForm = a[i].form;
			continue;
		}
		delete a[i].form;
	}
	if (foundForm == NULL)
		std::cout << "Intern: No form found, Sir!" << std::endl;
	return (foundForm);
}

// This is how I would normally do it, but STL is forbidden!
// std::map<std::string, AForm*> stringMap;
// stringMap["presidential pardon"] = new PresidentialPardonForm(target);
// stringMap["shrubbery creation"] = new ShrubberyCreationForm(target);
// stringMap["robotomy request"] = new RobotomyRequestForm(target);
// std::map<std::string, AForm*>::iterator it = stringMap.find(name);