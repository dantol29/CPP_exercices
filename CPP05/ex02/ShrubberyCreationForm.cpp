#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "Destructor called (ShrubberyCreationForm)" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj){
	std::cout << "Copy constructor called (ShrubberyCreationForm)" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj){
	std::cout << "Assignment operator called (ShrubberyCreationForm)" << std::endl;
	if (this != &obj)
		*this = obj;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery", 137, 145), _target(target){
	std::cout << "Target constructor called (ShrubberyCreationForm)" << std::endl;
}

int ShrubberyCreationForm::execute(const Bureaucrat& obj) const{
	try{
		if (this->getSigned() == false)
			throw("form is not signed!");
		if (this->getGradeToExecute() < obj.getGrade())
			throw(GradeTooLowException());
	}
	catch(const ShrubberyCreationForm::GradeTooLowException& obj){
		std::cout << "Exception caught: " << obj.what() << std::endl;
		return (0);
	}
	catch(...){
		std::cout << "Exception caught: " << "form is not signed!" << std::endl;
		return (0);
	}
	std::ofstream outputFile((_target + "_shrubbery").c_str());
	if (!outputFile.is_open()){
		std::cout << "Unable too create file" << std::endl;
		return (0);
	}
	outputFile << " * * * * *" << std::endl;
	outputFile << "* | | | | *" << std::endl;
	outputFile << "* | | | | *" << std::endl;
	outputFile << "* | | | | *" << std::endl;
	outputFile << "* | | | | *" << std::endl;
	outputFile << "* * | | * *" << std::endl;
	outputFile << "    | |    " << std::endl;
	outputFile.close();
	return (1);
}