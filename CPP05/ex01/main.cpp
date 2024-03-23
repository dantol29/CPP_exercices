#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
	Bureaucrat a(3, "Jack");
	Form b("Promotion", 3, 3);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	a.decrementGrade();
	std::cout << a << std::endl;
	a.signForm(b);
	a.incrementGrade();
	std::cout << a << std::endl;
	a.signForm(b);
	a.signForm(b);
	b.beSigned(a);
	std::cout << b << std::endl;
	a.incrementGrade();
	a.incrementGrade();
	a.incrementGrade();
	std::cout << a << std::endl;
}