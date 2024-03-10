
#include "Form.hpp"
int main()
{
	try{
		Bureaucrat b;
		Bureaucrat c(5);
		Form n("form1", 3, 1);
		std::cout << b;
		
		c.signForm(n);
	}
	catch(const Bureaucrat::GradeTooHightException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const Form::GradeTooHightException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	return(0);
}