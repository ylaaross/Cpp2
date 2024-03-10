#pragma once
#include <iostream>
class AForm;


class Bureaucrat
{
	private:
		std::string const  name;
		int grade;

	public:
		class GradeTooLowException:public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return("Grade is too low\n");
				}
		};

		class GradeTooHightException:public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return("Grade is too hight\n");
				}
		};
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &other);
		Bureaucrat(const Bureaucrat &other);

		
		Bureaucrat(int grade);
		void increment();
		void decrement();
		void signForm(AForm &f);
		std::string getName();
		int getGrade() const;
		void executeForm(AForm const & form);
};
std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat);