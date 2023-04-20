#include "ShrubberyCreationForm.hpp"
 
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm NoName", 145, 137) 
{ }

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name)
    : AForm(name, 145, 137)
{ }
ShrubberyCreationForm::~ShrubberyCreationForm() { }

#include <fstream>
#include "Bureaucrat.hpp"
void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    if (!this->getSign()) return ;
    try 
    {
        if (executor.getGrade() > this->getExcuteGrade())
        {
            std::cout << executor.getName() << " cannot execute " << this->getName() << " because ";
            throw GradeTooLowException();
        }
        std::string fileName = executor.getName() + "_shrubbery";
        std::fstream fs;
        fs.open(fileName.c_str(), std::fstream::out);
        if (!fs.is_open())
        {
            throw std::runtime_error("failed open");
        } 
        fs   << "           &&& &&  & &&\n"
                "      && &\\/&\\|& ()|/ @, &&\n"
                "      &\\/(/&/&||/& /_/)_&/_&\n"
                "   &() &\\/&|()|/&\\/ '%" "& ()\n"
                "  &_\\_\\&&_\\ |& |&&/&__%_/_& &&\n"
                "&&   && & &| &| /& & % ()& /&&\n"
                "()&_---()&\\&\\|&&-&&--%---()~\n"
                "     &&     \\|||\n"
                "             |||\n"
                "             |||\n"
                "             |||\n"
                "       , -=-~  .-^- _\n";
        fs.close();
        std::cout << executor.getName() << " executed " << this->getName() << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
