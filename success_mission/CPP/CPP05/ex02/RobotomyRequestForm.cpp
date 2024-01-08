#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::~RobotomyRequestForm() { }
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm NoName", 72, 45)
{ }

RobotomyRequestForm::RobotomyRequestForm(const std::string name)
	: AForm(name, 72, 45)
{ }

#include "Bureaucrat.hpp"
#include <cstdlib>
void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!this->getSign()) return ;
	try 
	{
		if (executor.getGrade() > this->getExcuteGrade())
		{
			throw GradeTooLowException();
		}
		std::cout << "drilllllllll" << std::endl;
		// reinterpret_cast는 컴파일 타임에 포인터를 인트로 바꾸는 명령어이다. 따라서 예측할 수 없는 동작을 한다.
		if (std::rand() % 2)
			std::cout << executor.getName() << " successfully" << std::endl;
		else
			std::cout << executor.getName() << " failed" << std::endl;
		std:: cout << executor.getName() << " executed " << this->getName() << std::endl;
	} catch (std::exception& e) {
		std::cerr << executor.getName() << " cannot execute " << this->getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
}
