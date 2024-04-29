#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(){
	Bureaucrat b(1, "Jack");
	Intern someRandomIntern;
	AForm* rrf;
	AForm* unknown;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	unknown = someRandomIntern.makeForm("earn money", "you");
	std::cout << "\n\n\n\n\n" << std::endl;
	std::cout << *rrf << std::endl;
	rrf->beSigned(b);
	rrf->execute(b);
	std::cout << "\n\n\n\n\n" << std::endl;
	delete rrf;
}