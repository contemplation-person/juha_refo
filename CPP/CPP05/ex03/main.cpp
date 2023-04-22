#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat test("test");
    test.setGrade(1);
    Intern intern;
    AForm* form = NULL ;
    form = intern.makeForm("bbery creation", "President");
    // form = NULL
    form = intern.makeForm("robotomy request", "Bender");
    form->beSigned(test);
    delete form;
    return 0;
}
