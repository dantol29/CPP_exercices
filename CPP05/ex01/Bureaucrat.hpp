#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
class Form;

class Bureaucrat{
	private:
		const std::string	_name;
		unsigned int		_grade;
		Bureaucrat();
	public:
		Bureaucrat(const Bureaucrat& obj);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& obj);
		Bureaucrat(unsigned int grade, std::string name);
		unsigned int getGrade() const;
		std::string getName() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form& obj);
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