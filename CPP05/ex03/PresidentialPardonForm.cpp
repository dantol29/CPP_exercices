#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "Destructor called (PresidentialPardonForm)" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj){
	std::cout << "Copy constructor called (PresidentialPardonForm)" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj){
	std::cout << "Assignment operator called (PresidentialPardonForm)" << std::endl;
	if (this != &obj)
		this->setSigned(obj.getSigned());
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("Presidential Pardon Form", 5, 25), _target(target){
	std::cout << "Target constructor called (PresidentialPardonForm)" << std::endl;
}

int PresidentialPardonForm::execute(const Bureaucrat& obj) const{
	if (this->getSigned() == false)
		throw("form is not signed!");
	if (this->getGradeToExecute() < obj.getGrade())
		throw(GradeTooLowException());
	std:: cout << "We inform that " << obj.getName() << "has been pardoned by Zaphod Beeblebrox." << std::endl;
	return (1);
}