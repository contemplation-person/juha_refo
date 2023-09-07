#include "Bureaucrat.hpp"
#include <string>
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
    if (this != &copy)
    {
        this->_name = copy._name;
        this->_grade = copy._grade;
    }
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
    return out << "=============Bureaucrat=============" << std::endl
               << "Bureaucrat name\t\t: " << b.getName() << std::endl 
               << "Bureaucrat grade\t: " << b.getGrade() << std::endl 
               << "==============endl==================" << std::endl;
}

void Bureaucrat::setGrade(const int& grade)
{
    try {
        if (150 < grade)
            throw Bureaucrat::GradeTooLowException();
        else if (1 > grade)
            throw Bureaucrat::GradeTooHighException();
        this->_grade = grade;
    } catch (std::exception& e) {
        std::cerr << "\033[31m" << e.what() << "\t: " 
                  << Bureaucrat::getName() << ", bureaucrat grade " << Bureaucrat::getGrade() << "\033[0m" 
                  << std::endl;
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
    return "\033[31mBur grade too high\033[0m";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
    return "\033[31mBur grade too low\033[0m";
}

#include "Form.hpp"

void Bureaucrat::signForm(Form& form)
{
    if (form.getSign())
        return ;
    try
    {
        if (form.getSignedGrade() < this->_grade)
            throw Bureaucrat::GradeTooLowException();
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() 
                  << std::endl;
    } catch (std::exception& e) {
        std::cout << this->_name << " couldn’t sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }

}
