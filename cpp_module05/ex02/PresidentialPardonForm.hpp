#pragma once
#include <fstream>
#include "AForm.hpp"

class PresidentialPardonForm: public AForm 
{
	private:
		std::string target;
	public:

		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &PresidentialPardonForm);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
		
		PresidentialPardonForm(std::string target);
		void beSigned(Bureaucrat s);
		void execute(Bureaucrat const & executor) const;
};