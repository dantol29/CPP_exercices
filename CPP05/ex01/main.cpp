#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	Bureaucrat a(3, "Jack");
	Form b("Promotion", 3, 3);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	a.decrementGrade();
	std::cout << a << std::endl;
	
	try {
		a.signForm(b);
	}
	catch (std::exception& e){
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (const char *errorMessage) {
		std::cerr << "Exception caught: " << errorMessage << std::endl;
	}

	a.incrementGrade();
	std::cout << a << std::endl;

	try {
		a.signForm(b);
		a.signForm(b);
	}
	catch (std::exception& e){
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (const char *errorMessage) {
		std::cerr << "Exception caught: " << errorMessage << std::endl;
	}

	try {
		b.beSigned(a);
	}
	catch (std::exception& e){
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	catch (const char *errorMessage) {
		std::cerr << "Exception caught: " << errorMessage << std::endl;
	}
}