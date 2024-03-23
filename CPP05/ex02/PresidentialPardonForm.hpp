#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	private:
		const std::string _target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(const std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
		int	execute(Bureaucrat const & executor) const;
};

#endif