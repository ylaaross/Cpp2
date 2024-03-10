#pragma once
#include <iostream>
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;
class AForm;

class Intern
{
	
	public:
			~Intern();
			Intern();
			Intern(const Intern &intern);
			Intern & operator=(const Intern &intern);

			AForm* mallocatePresidentialPardonForm(std::string target);
			AForm* mallocateRobotomyRequestForm(std::string target);
			AForm* mallocateShrubberyCreationForm(std::string target);
			AForm* makeForm(std::string name ,std::string target);
};
