#pragma once
#include <iostream>
// #include "Form.hpp"
class Form;

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
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);

		Bureaucrat(int grade);
		void increment();
		void decrement();
		void signForm(Form &f);
		std::string getName();
		int getGrade();	
		
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat);