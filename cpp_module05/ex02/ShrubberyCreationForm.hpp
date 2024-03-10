#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm 
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &ShrubberyCreationForm);
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
		void beSigned(Bureaucrat s);
		void execute(Bureaucrat const & executor) const;
};