#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <fstream>
#include <exception>
class Bureaucrat;

class AForm{
	private:
		const std::string		_name;
		bool					_signed;
		const unsigned int		_gradeToExecute;
		const unsigned int		_gradeToSign;
		unsigned int			validateNumber(unsigned int n) const;
		AForm();
	public:
		AForm(const AForm& obj);
		virtual ~AForm();
		AForm& operator=(const AForm& obj);
		AForm(const std::string name, const unsigned int gradeToExecute, const unsigned int gradeToSign);
		void				beSigned(const Bureaucrat& obj);
		const std::string	getName() const;
		bool				getSigned() const;
		unsigned int		getGradeToExecute() const;
		unsigned int		getGradeToSign() const;
		void				setSigned(bool n);
		virtual int			execute(Bureaucrat const & executor) const = 0;
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

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif