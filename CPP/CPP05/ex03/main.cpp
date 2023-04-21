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
    AForm* form;
    form = intern.makeForm("shrubbery creation", "President");
    form->beSigned(test);
    delete form;
    return 0;
}
