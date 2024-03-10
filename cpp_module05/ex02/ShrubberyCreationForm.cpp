#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"



ShrubberyCreationForm::ShrubberyCreationForm():AForm("FormShrubbery", 25, 5)
{
    target = "targetShrubbery";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ShrubberyCreationForm):AForm(ShrubberyCreationForm.getname(),ShrubberyCreationForm.getGradets(),ShrubberyCreationForm.getGradete())
{
    this->target = ShrubberyCreationForm.target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
        target = other.target;
    return *this;
}

void ShrubberyCreationForm::beSigned(Bureaucrat const s)
{
    if(s.getGrade() <= getGradets())
        set_signe();
    else
        throw GradeTooLowException();
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() <= getGradete() && getIsSigned())
    {
        std::cout <<  " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }   
    else
        std::cout <<  "Error" << std::endl;
}