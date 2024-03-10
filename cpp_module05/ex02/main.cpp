
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
int main()
{
	try{
		Bureaucrat b(1);
		 AForm   *m = new ShrubberyCreationForm();
		b.signForm(*m);
		b.executeForm(*m);
		b.executeForm(*m);
	}
	catch(const Bureaucrat::GradeTooHightException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const AForm::GradeTooHightException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return(0);
}









