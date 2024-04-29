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

	a.executeForm(*b);
	a.signForm(*b);
	a.executeForm(*b);
	c.executeForm(*b);
	a.signForm(*president);
	a.executeForm(*president);
	c.executeForm(*president);
	a.signForm(*robot);
	a.executeForm(*robot);
	robot->execute(a);
	robot->execute(c);
	delete b;
	delete robot;
	delete president;
}