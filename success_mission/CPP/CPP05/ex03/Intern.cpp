#include "Intern.hpp"

Intern::Intern() { }
Intern::~Intern() { }

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	try
	{
		int i = 0; 
		while (i < 3 && forms[i] != formName)
			++i;
		if (i == 3)
			throw "\033[31mForm not found\033[0m";
		std::cout << "Intern creates " << formName << std::endl;
		switch(i)
		{
			case 0:
				return new ShrubberyCreationForm(target);
			case 1:
				return new RobotomyRequestForm(target);
			case 2:
				return new PresidentialPardonForm(target);
		}
	}
	catch(const char* e)
	{
		std::cerr << e << '\n';
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return NULL;
}
