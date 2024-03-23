#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
class Bureaucrat;

class Form{
	private:
		const std::string		_name;
		bool					_signed;
		const unsigned int		_gradeToExecute;
		const unsigned int		_gradeToSign;
		Form();
		unsigned int			validateNumber(unsigned int n) const;
	public:
		Form(const Form& obj);
		~Form();
		Form(const std::string name, const unsigned int gradeToExecute, const unsigned int gradeToSign);
		Form& operator=(const Form& obj);
		void				beSigned(const Bureaucrat& obj);
		const std::string	getName() const;
		bool				getSigned() const;
		unsigned int	getGradeToExecute() const;
		unsigned int	getGradeToSign() const;
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

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif