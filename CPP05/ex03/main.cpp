#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(){
	Intern someRandomIntern;
	AForm* rrf;
	AForm* unknown;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	unknown = someRandomIntern.makeForm("earn money", "you");
	std::cout << *rrf << std::endl;
	delete rrf;
}