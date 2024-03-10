#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm():AForm( "defaultShrubbery", 145, 137)
{
    std::cout << "Default constructore of Shrubbery is called" << std::endl;
    target = "ShrubberyTarget";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "Copy assignement operator for Shrubbery" << std::endl;
    if (this != &other)
        target = other.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "The destructor of Shrubbery is called" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ShrubberyCreationForm):AForm(ShrubberyCreationForm.getname(), ShrubberyCreationForm.getGradets(), ShrubberyCreationForm.getGradete())
{
     std::cout << "Copy assignement operator for Shrubbery" << std::endl;
    this->target = ShrubberyCreationForm.target;
}





void ShrubberyCreationForm::beSigned(Bureaucrat const s)
{
    if(s.getGrade() <= getGradets())
        set_signe();
    else
        throw GradeTooLowException();
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm( "defaultShrubbery", 145, 137)
{
    this->target = target;
}
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() <= getGradete() && getIsSigned())
        std::cout << target  << "has been pardoned by Zaphod Beeblebrox" << std::endl;
    else
        std::cout << target  << "cannot execute the form" << std::endl;
}