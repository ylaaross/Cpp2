#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::~Bureaucrat()
{
	std::cout << "bureaucrat is destroyed\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other) // Check for self-assignment
    {
		std::cout << "Copy assignment operator called" << std::endl;
        grade = other.grade;
    }
    return *this;
}
std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat)
{
	return os << bureaucrat.getName() << ", bureaucrat grade "<< bureaucrat.getGrade() << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this =	 other;
}
Bureaucrat::Bureaucrat():name("default")
{
	std::cout << "default constructor is called\n" << std::endl;
	grade = 150;
}
Bureaucrat::Bureaucrat(int grade):name("default")
{
	this->grade = grade;
}
std::string Bureaucrat::getName()
{
	return(name);
}
int Bureaucrat::getGrade() const
{
	return(grade);
}
void Bureaucrat::increment()
{
	if(grade == 1)
		throw GradeTooHightException();
	grade--;
}
void Bureaucrat::decrement()
{
	if(grade == 150)
		throw GradeTooLowException();
	grade++;
}
void Bureaucrat::signForm(AForm &f)
{
	std::cout << "grade of " << f.getGrade();
	if (f.getGrade() >= grade)
	{
		std::cout << name << " signed " << f.getname() << "\n";
		f.beSigned(*this);
	}
	else
		std::cout << name << " couldn’t sign " << f.getname() << " because the grade is too low" << std::endl ;
}
void Bureaucrat::executeForm(AForm const & form)
{
	
	if(form.getGradete() >= grade && form.getIsSigned())
	{
		std::cout << name << " executed " << form.getname() << std::endl;
		form.execute(*this);
	}
	else
		std::cout << "Error cannot execute the form" << std::endl;
}