#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

Form::~Form(){
	std::cout << "Default destructor called" << std::endl;
}

Form::Form(const Form& obj) : _name(obj._name), _signed(obj._signed), _gradeToExecute(obj._gradeToExecute), _gradeToSign(obj._gradeToSign){
	std::cout << "Copy constructor called" << std::endl;
}

Form::Form(const std::string name, const unsigned int gradeToExecute, const unsigned int gradeToSign) : _name(name), \
_signed(false), _gradeToExecute(validateNumber(gradeToExecute)), _gradeToSign(validateNumber(gradeToSign))
{
	std::cout << "Name constructor called" << std::endl;
		
}

unsigned int Form::validateNumber(unsigned int n) const{
	try{
		if (n < 1)
			throw(GradeTooHighException());
		else if (n > 150)
			throw(GradeTooLowException());
	}
	catch(const Form::GradeTooLowException& obj){
		std::cout << "Exception caught: " << obj.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	catch(const Form::GradeTooHighException& obj){
		std::cout << "Exception caught: " << obj.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	return (n);
}

unsigned int Form::getGradeToExecute() const{
	return (_gradeToExecute);
}

unsigned int Form::getGradeToSign() const{
	return (_gradeToSign);
}

bool Form::getSigned() const{
	return (_signed);
}

const std::string Form::getName() const{
	return (_name);
}

void Form::beSigned(const Bureaucrat& obj){
	try{
		if (obj.getGrade() > _gradeToSign)
			throw(GradeTooLowException());
		if (_signed == true)
			throw("form is already signed");
		_signed = true;
	}
	catch(const Form::GradeTooLowException& obj){
		std::cout << "Exception caught: " << obj.what() << std::endl;
	}
	catch(...){
		std::cout << "Exception caught: " << "form is already signed" << std::endl;
	}
}

Form& Form::operator=(const Form& obj){
	std::cout << "Assignment operator called" << std::endl;
	if (this != &obj){
		_signed = obj._signed;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Form& obj){
	out << obj.getName() << ", form is signed["<< obj.getSigned() << "] grade to sign[" << obj.getGradeToSign()\
	<< "] grade to execute [" << obj.getGradeToExecute() << "]";
	return (out);
}