#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>


class Form{
	private:
		const std::string		_name;
		bool					_signed;
		const unsigned int		_gradeToExecure;
		const unsigned int		_gradeToSign;
	public:
		Form();
		Form(const Form& obj);
		~Form();
		Form& operator=(const Form& obj);
		Form(std::string name);
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


#endif