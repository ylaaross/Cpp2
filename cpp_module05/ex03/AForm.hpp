#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
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
		AForm();
		virtual ~AForm();
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);
		AForm(std::string name, int gradets, int gardete);
		virtual void beSigned(Bureaucrat s) = 0;
		virtual void execute(Bureaucrat const & executor) const = 0;
		void set_name();

		int getGrade();
		bool getIsSigned() const;
		int getGradets() const;
		int getGradete() const;
		std::string getname() const;
		void set_signe();
};

void operator<<(std::ostream &cout, AForm &f);