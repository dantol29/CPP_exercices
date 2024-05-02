#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "Destructor called (RobotomyRequestForm)" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj){
	std::cout << "Copy constructor called (RobotomyRequestForm)" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj){
	std::cout << "Assignment operator called (RobotomyRequestForm)" << std::endl;
	if (this != &obj)
		*this = obj;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("PRobotomy Request Form", 45, 72), _target(target){
	std::cout << "Target constructor called (RobotomyRequestForm)" << std::endl;
}

int RobotomyRequestForm::execute(const Bureaucrat& obj) const{
	if (this->getSigned() == false)
		throw("form is not signed!");
	if (this->getGradeToExecute() < obj.getGrade())
		throw(GradeTooLowException());
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int range = 2;
	int a = std::rand() % range;
	if (a == 1)
		std::cout << obj.getName() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy on " << obj.getName() << " failed" << std::endl;
	return (1);
}