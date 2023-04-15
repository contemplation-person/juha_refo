#include "Bureaucrat.hpp"
#include "MyException.hpp"

//	this subject is using try/catch for error handling
//	grade range is 1 to 150
Bureaucrat::Bureaucrat() 
    :_name("noName"), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string name)
    : _name(name), _grade(150)
{}

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

void		Bureaucrat::setGrade(const int& grade)
{
    try {
        if (150 < grade)
            throw GradeTooHighException(__LINE__, __FILE__, _name, _grade);
        else if (1 > grade)
            throw GradeTooLowException(__LINE__, __FILE__, _name, _grade);
        this->_grade = grade;
    } catch (GradeTooHighException& e) {
        e.print();
    } catch (GradeTooLowException& e) {
        e.print();
    }
}

void		Bureaucrat::setName(const std::string& name) 
{
    this->_name = name;
}

int			Bureaucrat::getGrade() const
{
    return (this->_grade);
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

void        Bureaucrat::increment()
{
    setGrade(getGrade() - 1);
}

void        Bureaucrat::decrement()
{
    setGrade(getGrade() + 1);
}
