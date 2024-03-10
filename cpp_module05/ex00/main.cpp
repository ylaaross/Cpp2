#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b(-1);
		b.decrement();
		std::cout << b << b;
	}
	catch(const Bureaucrat::GradeTooHightException& e)
	{
		std::cout << e.what() << std::endl;
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}

	return(0);
}