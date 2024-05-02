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
	std::cout << "\n\n\n\n\n\n" << std::endl;

	try {
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		rrf->beSigned(b);
		rrf->execute(b);
		delete rrf;
		unknown = someRandomIntern.makeForm("earn money", "you");
	}
	catch (std::exception& e){
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (const char *errorMessage) {
		std::cerr << "Exception caught: " << errorMessage << std::endl;
	}
	std::cout << "\n\n\n\n\n\n" << std::endl;
}