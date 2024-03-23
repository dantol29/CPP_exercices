#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	private:
		const std::string _target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(const std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
		int	execute(Bureaucrat const & executor) const;
};

#endif