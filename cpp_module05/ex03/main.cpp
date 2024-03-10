#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
int main()
{
	try{
		Bureaucrat b(3);
		// const AForm   *m = new PresidentialPardonForm();
		// b.executeForm(*m);
		// b.executeForm(*m);
		AForm *d;
		Intern s;
		RobotomyRequestForm f;
		RobotomyRequestForm g;
		// std::cout << f.getGrade();
		std::cout << " ";
		d = s.makeForm("presidential pardon","lbts akhouya");
		d = s.makeForm("robotomy request","lbts akhouya");
		// std::cout << d->getname();
		b.signForm(*d);
		// b.executeForm(*d);
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









