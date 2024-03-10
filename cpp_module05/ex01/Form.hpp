#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private :
		std::string const name;
		bool isSigned;
		int const gradets;
		int const gradete;
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
		Form();
		~Form();
		Form(const Form &other);
		Form& operator=(const Form &other);
			
		Form(std::string name, int gradets, int gardete);
		void beSigned(Bureaucrat const s);
		int getGrade();
		bool getIsSigned();
		int getGradets();
		int getGradete();
		std::string getname();

		// std::ostream& operator<<(std::ostream& cout, const Fixed& fixedPoint);
};

void operator<<(std::ostream &cout, Form &f);