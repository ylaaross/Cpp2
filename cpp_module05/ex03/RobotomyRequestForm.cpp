#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("FormRobotomy", 72, 45)
{
    target = "targetRobotomy";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &RobotomyRequestForm):AForm(RobotomyRequestForm.getname(),RobotomyRequestForm.getGradets(),RobotomyRequestForm.getGradete())
{
    this->target = RobotomyRequestForm.target;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "copy assignment operator for RobotomyRequestForm is called" << std::endl;
    if (this != &other)
        target = other.target;
    return *this;
}

void RobotomyRequestForm::beSigned(Bureaucrat const s)
{
    if(s.getGrade() <= getGradets())
        set_signe();
    else
        throw GradeTooLowException();
}



RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm( "defaultRobotomy", 72, 45)
{
    this->target = target;
}
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    static int i = 1;

    if (executor.getGrade() <= getGradete() && getIsSigned())
    {
        if(i == 1)
        {
            i = 0;
            std::cout << target << " has been robotomized" << std::endl;
        }
        else
        {
            i = 1;
            std::cout <<  "has been failed" << std::endl;
        }
    }
    else
          std::cout << target  << "cannot execute the form" << std::endl;
}