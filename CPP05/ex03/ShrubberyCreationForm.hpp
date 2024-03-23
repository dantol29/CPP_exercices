#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{
	private:
		const std::string _target;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(const std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
		int	execute(Bureaucrat const & executor) const;
};

#endif