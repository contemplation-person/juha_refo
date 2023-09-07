#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat bureaucrat;
    Bureaucrat admin("admin");
    admin.setGrade(1);
    ShrubberyCreationForm s("shrubbery");
    RobotomyRequestForm r("robotomy");
    PresidentialPardonForm p("pardon");

    bureaucrat.signForm(s);
    bureaucrat.signForm(r);
    bureaucrat.signForm(p);
    admin.signForm(s);
    admin.signForm(r);
    admin.signForm(p);

    bureaucrat.executeForm(s);
    bureaucrat.executeForm(r);
    bureaucrat.executeForm(p);

    admin.executeForm(s);
    admin.executeForm(r);
    admin.executeForm(p);


    

	return 0;
}
