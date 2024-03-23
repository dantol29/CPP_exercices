#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::~AForm(){
	std::cout << "Default destructor called" << std::endl;
}

AForm::AForm(const AForm& obj) : _name(obj._name), _signed(obj._signed), _gradeToExecute(obj._gradeToExecute), _gradeToSign(obj._gradeToSign){
	std::cout << "Copy constructor called" << std::endl;
}

AForm::AForm(const std::string name, const unsigned int gradeToExecute, const unsigned int gradeToSign) : _name(name),\
 _signed(false), _gradeToExecute(validateNumber(gradeToExecute)), _gradeToSign(validateNumber(gradeToSign)){
	std::cout << "Name constructor called" << std::endl;
}

unsigned int AForm::validateNumber(unsigned int n) const{
	try{
		if (n < 1)
			throw(GradeTooHighException());
		else if (n > 150)
			throw(GradeTooLowException());
	}
	catch(const AForm::GradeTooLowException& obj){
		std::cout << "Exception caught: " << obj.what() << std::endl;
	}
	catch(const AForm::GradeTooHighException& obj){
		std::cout << "Exception caught: " << obj.what() << std::endl;
	}
	return (n);
}

unsigned int AForm::getGradeToExecute() const{
	return (_gradeToExecute);
}

unsigned int AForm::getGradeToSign() const{
	return (_gradeToSign);
}

bool AForm::getSigned() const{
	return (_signed);
}

const std::string AForm::getName() const{
	return (_name);
}

void AForm::beSigned(const Bureaucrat& obj){
	try{
		if (obj.getGrade() > _gradeToSign)
			throw(GradeTooLowException());
		if (_signed == true)
			throw("form is already signed");
		_signed = true;
	}
	catch(const AForm::GradeTooLowException& obj){
		std::cout << "Exception caught: " << obj.what() << std::endl;
	}
	catch(...){
		std::cout << "Exception caught: " << "form is already signed" << std::endl;
	}
}

void AForm::setSigned(bool n){
	_signed = n;
}

AForm& AForm::operator=(const AForm& obj){
	std::cout << "Assignment operator called" << std::endl;
	if (this != &obj){
		_signed = obj._signed;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const AForm& obj){
	out << obj.getName() << ", form is signed["<< obj.getSigned() << "] grade to sign[" << obj.getGradeToSign()\
	<< "] grade to execute [" << obj.getGradeToExecute() << "]";
	return (out);
}