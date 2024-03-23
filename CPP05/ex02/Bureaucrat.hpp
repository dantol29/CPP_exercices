#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
class AForm;

class Bureaucrat{
	private:
		const std::string	_name;
		unsigned int		_grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& obj);
		Bureaucrat(unsigned int grade, std::string name);
		unsigned int getGrade() const;
		std::string getName() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm& obj);
		void executeForm(const AForm& form);
		class GradeTooLowException : public std::exception{
			public:
				const char* what() const throw(){
					return ("Grade is too low");
				}
		};
		class GradeTooHighException : public std::exception{
			public:
				const char* what() const throw(){
					return ("Grade is too high");
				}
		};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif