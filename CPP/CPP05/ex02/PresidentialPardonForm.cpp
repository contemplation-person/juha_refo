#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm NoName", 25, 5)
{ }

PresidentialPardonForm::PresidentialPardonForm(const std::string name)
	: AForm(name, 25, 5)
{ }

PresidentialPardonForm::~PresidentialPardonForm()
{ }

#include "Bureaucrat.hpp"
void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (this->getSign()) return ;
	try
	{
		if (executor.getGrade() > this->getExcuteGrade())
		{
			throw GradeTooLowException();
		}
		std::cout << executor.getName() << " Zafod Beeblebrox에 의해 사면 됨" << std::endl;
		std:: cout << executor.getName() << " executed " << this->getName() << std::endl;
	} catch (std::exception& e) {
		std::cerr<< executor.getName() << " cannot execute " << this->getName() << " because ";
		std::cerr<< e.what() << std::endl;
	}
}