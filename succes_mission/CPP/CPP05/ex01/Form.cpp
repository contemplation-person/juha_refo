#include "Form.hpp"
#include "Bureaucrat.hpp"

const char * Form::GradeTooHighException::what() const throw()
{
    return "\033[31mForm grade too high\033[0m";
}

const char * Form::GradeTooLowException::what() const throw()
{
    return "\033[31mForm grade too low\033[0m";
}

Form::Form()
    : _name("no Name"), _sign(false), _signedGrade(30), _excuteGrade(1)
{ }

Form::Form(const std::string name, const int signedGrade, const int excuteGrade)
    : _name(name), _sign(false), _signedGrade(signedGrade), _excuteGrade(excuteGrade)
{ }

Form::~Form() { }

void Form::setSign(bool sign)
{
    if (_sign)
        return ;
    this->_sign = sign;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    try 
    {
        if (bureaucrat.getGrade() > this->getSignedGrade())
            throw Form::GradeTooLowException();
        this->setSign(true);
    } catch (std::exception& e) {
        std::cerr << e.what() <<std::endl;
    }
}

int Form::getSign()
{
    return _sign;
}

const std::string Form::getName()
{
    return _name;
}

int Form::getSignedGrade()
{
    return _signedGrade;
}

int Form::getExcuteGrade()
{
    return _excuteGrade;
}

std::ostream& operator<<(std::ostream& o, Form& f)
{
    return o << "==============form=================="<< std::endl
             << "name\t\t: " << f.getName() << std::endl
             << "signed\t\t: " << (f.getSign() ? "TRUE" : "FALSE") << std::endl
             << "signedGrade\t: " << f.getSignedGrade() << std::endl
             << "excuteGrade\t: " << f.getExcuteGrade() << std::endl
             << "==============endl==================" << std::endl;
} 

