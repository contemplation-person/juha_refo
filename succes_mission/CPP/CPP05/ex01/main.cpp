#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat bureaucrat;
    Bureaucrat admin("admin");
    Form       form("test", 20, 15);
    admin.setGrade(1);

    bureaucrat.signForm(form);
    admin.signForm(form);
    bureaucrat.signForm(form);

    std::cout << admin << std::endl;
    std::cout << form << std::endl;
	return 0;
}
