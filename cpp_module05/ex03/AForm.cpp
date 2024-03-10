#include "AForm.hpp"

AForm::~AForm()
{
	std::cout << "Form is destroyed\n";
}

AForm& AForm::operator=(const AForm &other)
{
    	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
	    isSigned = other.isSigned;
    return *this;
}



AForm::AForm():name("defaultForm"),isSigned(0),gradets(50),gradete(10)
{
}

AForm::AForm(const AForm &other):name(other.name),gradets(other.gradets),gradete(other.gradete)
{
}

void AForm::beSigned(Bureaucrat s)
{

    if(s.getGrade() <= gradets)
        isSigned = 1;
    else
        throw GradeTooLowException();
}

int AForm::getGrade()
{
    return (gradets);
}

AForm::AForm(std::string name, int  gradets, int  gradete):name(name),gradets(gradets),gradete(gradete)
{
    if (gradets > 150)
		throw GradeTooLowException();
    if (gradets < 1)
        throw GradeTooHightException();
    this->isSigned = 0;
}

void AForm::set_signe()  
{
    isSigned = 1;
}

std::string AForm::getname()const
{
    return name;  
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradets() const
{
    return gradets;
}

int AForm::getGradete() const
{
    return gradete;
}

void operator<<(std::ostream &cout, AForm &f)
{
    cout << "Name of the form is " << f.getname() << std::endl;
    cout << "Is signed = " << f.getIsSigned() << std::endl;
    cout << "The grade that it's required to signe is" << f.getGradets() << std::endl;
	cout << "The grade that it's required to signe is" << f.getGradete() << std::endl;
}