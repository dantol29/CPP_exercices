#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(){
	Bureaucrat a(3, "Jack");
	Bureaucrat c(150, "Karl");
	AForm* b = new ShrubberyCreationForm("home");
	AForm* president = new PresidentialPardonForm("Joshua");
	AForm* robot = new RobotomyRequestForm("John");
	std::cout << a << std::endl;
	a.executeForm(*b);
	a.signForm(*b);
	a.executeForm(*b);
	c.executeForm(*b);
	a.signForm(*president);
	a.executeForm(*president);
	a.signForm(*robot);
	a.executeForm(*robot);
}