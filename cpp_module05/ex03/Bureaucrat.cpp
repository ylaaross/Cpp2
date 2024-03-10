#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::~Bureaucrat()
{
	std::cout << "bureaucrat is destroyed\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
		grade = other.grade;
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
	if (f.getGrade() >= grade)
	{
		std::cout << name << " signed " << f.getname() << "\n";
		f.beSigned(*this);
	}
	else
		std::cout << name << " couldn’t sign " << f.getname() << " because the grade is too low\n";
}
void Bureaucrat::executeForm(AForm const & form)
{
	if(form.getGradete() >= grade && form.getIsSigned())
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getname() << std::endl;
	}
	else
		std::cout << "error"<< std::endl;
}