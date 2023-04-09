#include "Bureaucrat.hpp"

//	this subject is using try/catch for error handling
//	grade range is 1 to 150
Bureaucrat::Bureaucrat(std::string name)
	: _name(name), _grade(150)
{ }
Bureaucrat::~Bureaucrat() { }
Bureaucrat::Bureaucrat(const Bureaucrat &copy) { *this = copy; }
const Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this == &copy)
	{
		this->_name = copy._name;
		this->_grade = copy._grade;
	}
	return (*this);
}

void		setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

void		setName(std::string name) 
{
	this->_name = name;
}

int			getGrade()
{
	return (this->_grade);
}

std::string getName()
{
	return (this->_name);
}
