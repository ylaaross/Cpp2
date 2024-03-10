#include <iostream>
	

class Bureaucrat
{
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
	std::string const  name;
	int grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat &other);
		Bureaucrat(const Bureaucrat &other);
	
		Bureaucrat(int grade);
		void increment();
		void decrement();
		std::string getName();
		int getGrade();	
};
	std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat);

