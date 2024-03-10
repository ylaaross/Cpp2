#include "Form.hpp"

Form::~Form()
{
	std::cout << "Form is destroyed\n";
}

Form& Form::operator=(const Form &other)
{
    if (this != &other)
    {
		std::cout << "Copy assignment operator called" << std::endl;
        isSigned = other.isSigned;
    }
    return *this;
}


Form::Form():name("form1"),gradets(50),gradete(10)
{ 
}

Form::Form(const Form &other):name(other.name),gradets(other.gradets),gradete(other.gradete)
{
}

void Form::beSigned(Bureaucrat s)
{

    if(s.getGrade() <= gradets)
        isSigned = 1;
    else
        throw GradeTooLowException();
}

int Form::getGrade()
{
    return (gradets);
}

Form::Form(std::string name, int  gradets, int  gradete):name(name),gradets(gradets),gradete(gradete)
{
    if (gradets > 150)
		throw GradeTooLowException();
    if (gradets < 1)
        throw GradeTooHightException();
    this->isSigned = 0;
}


std::string Form::getname()
{
    return name;  
}

bool Form::getIsSigned()
{
    return isSigned;
}

int Form::getGradets()
{
    return gradets;
}

int Form::getGradete()
{
    return gradete;
}

void operator<<(std::ostream &cout, Form &f)
{
    cout << "Name of the form is " << f.getname() << std::endl;
    cout << "Is signed = " << f.getIsSigned() << std::endl;
    cout << "The grade that it's required to signe is" << f.getGradets() << std::endl;
	cout << "The grade that it's required to signe is" << f.getGradete() << std::endl;
}