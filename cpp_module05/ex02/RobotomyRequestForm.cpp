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

void    RobotomyRequestForm::execute(Bureaucrat const & executor)const 
{
    if(executor.getGrade() <= getGradete() && getIsSigned())
        std::cout << target << " has been robotomized successfully 50\% of the time" << std::endl;
    else
        std::cout << "robotomy failed" << std::endl;
}