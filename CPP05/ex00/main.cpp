#include "Bureaucrat.hpp"

int main(){
	Bureaucrat a(2, "Jack");

	std::cout << a << std::endl;
	try{
		a.incrementGrade();
	}
	catch (const std::exception& e){
		std::cout << "Exception caught " << e.what() << std::endl;
	}
	std::cout << a << std::endl;
	try{
		a.incrementGrade();
	}
	catch (const std::exception& e){
		std::cout << "Exception caught " << e.what() << std::endl;
	}
	std::cout << a << std::endl;
	try{
		a.decrementGrade();
	}
	catch (const std::exception& e){
		std::cout << "Exception caught " << e.what() << std::endl;
	}
	std::cout << a << std::endl;
	try{
		Bureaucrat b(151, "Jack");
	}
	catch (const std::exception& e){
		std::cout << "Exception caught " << e.what() << std::endl;
	}
}