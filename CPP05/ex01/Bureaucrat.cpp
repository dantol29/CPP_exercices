#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("name is unknown"), _grade(0){
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Default destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj._name), _grade(obj._grade){
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(unsigned int grade, std::string name) : _name(name){
	std::cout << "Name constructor called" << std::endl;
	if (grade < 1)
		throw(GradeTooHighException());
	else if (grade > 150)
		throw(GradeTooLowException());
	_grade = grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj){
	std::cout << "Assignment operator called" << std::endl;
	if (this != &obj){
		_grade = obj._grade;
	}
	return (*this);
}

unsigned int Bureaucrat::getGrade() const{
	return (_grade);
}

std::string Bureaucrat::getName() const{
	return (_name);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj){
	out << obj.getName() << ", bureaucrat grade "<< obj.getGrade();
	return (out);
}

void Bureaucrat::incrementGrade(){
	if (_grade - 1 < 1)
		throw(GradeTooHighException());
	_grade -= 1;
}

void Bureaucrat::decrementGrade(){
	if (_grade + 1 > 150)
		throw(GradeTooLowException());
	_grade += 1;
}

void Bureaucrat::signForm(Form& obj){
	if (obj.getGradeToSign() < _grade){
		std::cout << _name << " couldn't signed " << obj.getName() << " because ";
		throw(GradeTooLowException());
	}
	if (obj.getSigned() == true){
		std::cout << _name << " couldn't signed " << obj.getName() << " because ";
		throw("form is already signed");
	}
	obj.beSigned(*this);
	std::cout << _name << " signed " << obj.getName() << std::endl;
}