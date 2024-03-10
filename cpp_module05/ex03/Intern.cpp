#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

Intern::~Intern()
{
	std::cout << "the destructor of the class Intern is called" << std::endl;
}

Intern::Intern()
{
	std::cout << "the default constructor of the class Intern is called" << std::endl;
}



Intern& Intern::operator=(const Intern & intern)
{
	(void) intern;
	return *this;
}

Intern::Intern(const Intern & intern)
{
	*this = intern;
	std::cout << "the copy constructor of the class Intern is called" << std::endl;
}

AForm* Intern::mallocatePresidentialPardonForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::mallocateRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::mallocateShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	int f = -1;
	int i = 0;
	std::string s[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
 AForm* (Intern::*operations[3])(std::string)  = {
        &Intern::mallocatePresidentialPardonForm,
        &Intern::mallocateRobotomyRequestForm,
        &Intern::mallocateShrubberyCreationForm
    };
	while(i < 3)
	{
		if(s[i] == name)
		{
			f = i;
			break;
		}
		i++;
	}
	if(f != -1)
		return (this->*operations[f])(target);
	return(NULL);
}
