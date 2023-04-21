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
		std::size_t i = 0; 
		while (i < forms->length() && forms[i] != formName)
			++i;
		if (i == forms->length())
			throw "Form not found";
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
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return NULL;
}
