#include "Bureaucrat.hpp"

//	this subject is using try/catch for error handling
//	grade range is 1 to 150
Bureaucrat::Bureaucrat() 
    : _name("noName"), _grade(150)
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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    return out << "name\t: " << b.getName() << "grade" << b.getGrade() << std::endl;
}
void Bureaucrat::setGrade(const int& grade)
{
    try {
        if (150 < grade)
            throw Bureaucrat::GradeTooHighException();
        else if (1 > grade)
            throw Bureaucrat::GradeTooLowException();
        this->_grade = grade;
    } catch (std::exception& e) {
        std::cout << "\033[31m" << e.what() << "\t: " << Bureaucrat::getName() << ", bureaucrat grade " << Bureaucrat::getGrade() << "\033[0m" << std::endl;
    }
}

void Bureaucrat::setName(const std::string& name) 
{
    this->_name = name;
}

int	Bureaucrat::getGrade() const
{
    return (this->_grade);
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

void Bureaucrat::increment()
{
    setGrade(getGrade() - 1);
}

void Bureaucrat::decrement()
{
    setGrade(getGrade() + 1);
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
    return "grade too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
    return "grade too low";
}
