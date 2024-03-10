#pragma once
#include "AForm.hpp"

class RobotomyRequestForm: public AForm 
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &robotomy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
		RobotomyRequestForm(std::string target);
		void beSigned(Bureaucrat s);
		void execute(Bureaucrat const & executor) const;
};