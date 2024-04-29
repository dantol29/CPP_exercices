#include "Bureaucrat.hpp"

int main(){
	Bureaucrat a(2, "Jack");

	std::cout << a << std::endl;
	a.incrementGrade();
	std::cout << a << std::endl;
	a.incrementGrade();
	std::cout << a << std::endl;
	a.decrementGrade();
	std::cout << a << std::endl;
	Bureaucrat b(151, "Jack");
}