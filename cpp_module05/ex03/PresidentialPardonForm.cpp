#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("FormPresidential",145,135)
{
    target = "targetPresidential";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &PresidentialPardonForm):AForm(PresidentialPardonForm.getname(),PresidentialPardonForm.getGradets(),PresidentialPardonForm.getGradete())
{
    std::cout << "copy constructore of Presidential" << std::endl;
    this->target = PresidentialPardonForm.target;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "The destructor of Presidential is called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "copy assignement operator of Presidential is called" << std::endl;
    if (this != &other)
        target = other.target;
    return *this;
}



void PresidentialPardonForm::beSigned(Bureaucrat const s)
{
    if(s.getGrade() <= getGradets())
        set_signe();
    else
        throw GradeTooLowException();
}



void open(std::string str)
{
    std::string filename = str + "_shrubbery";
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) 
    {
        outputFile << "          &&& &&  & &&" << std::endl;
        outputFile << "      && &\\/&\\|& ()|/ @, &&"<< std::endl;
        outputFile << "      &\\/(/&/&||/& /_/)_&/_&"<< std::endl;
        outputFile << "   &() &\\/&|()|/&\\/ %\\  & ("<< std::endl;
        outputFile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&"<< std::endl;
        outputFile << "&&   && & &| &| /& & % ()& /&&"<< std::endl;
        outputFile << " ()&_---()&\\&\\|&&-&&--%---()~"<< std::endl;
        outputFile << " ()&_---()&\\&\\|&&-&&--%---()~"<< std::endl;
        outputFile << " ()&_---()&\\&\\|&&-&&--%---()~"<< std::endl;
        outputFile << " ()&_---()&\\&\\|&&-&&--%---()~"<< std::endl;
        outputFile << "     &&     \\|||"<< std::endl;
        outputFile << "             |||"<< std::endl;
        outputFile << "             |||"<< std::endl;
        outputFile << "             |||"<< std::endl;
        outputFile << "       , -=-~  .-^- _"<< std::endl;
        outputFile.close();
    }
    else 
        std::cerr << "Unable to create the file: " << filename << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() <= getGradete() && getIsSigned())
        open(target);
    else
        throw GradeTooLowException();
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("Form1",145,135)
{
    this->target = target;
}