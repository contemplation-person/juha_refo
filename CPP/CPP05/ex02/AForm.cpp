#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char * AForm::GradeTooHighException::what() const throw()
{
    return "\033[31mAForm grade too high\033[0m";
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return "\033[31mAForm grade too low\033[0m";
}

AForm::AForm()
    : _name("no Name"), _sign(false), _signedGrade(30), _excuteGrade(1)
{ }

AForm::AForm(const std::string name, const int signedGrade, const int excuteGrade)
    : _name(name), _sign(false), _signedGrade(signedGrade), _excuteGrade(excuteGrade)
{ }

AForm::~AForm() { }

void AForm::setSign(bool sign)
{
    if (_sign)
        return ;
    this->_sign = sign;
}

/*
void AForm::beSigned(Bureaucrat& bureaucrat)
{
    try 
    {
        if (bureaucrat.getGrade() < this->getSignedGrade())
            throw AForm::GradeTooLowException();
        this->setSign(true);
    } catch (std::exception& e) {
        std::cout << e.what() <<std::endl;
    }
}
*/

int AForm::getSign()
{
    return _sign;
}

const std::string AForm::getName()
{
    return _name;
}

int AForm::getSignedGrade()
{
    return _signedGrade;
}

int AForm::getExcuteGrade()
{
    return _excuteGrade;
}

std::ostream& operator<<(std::ostream& o, AForm& f)
{
    return o << "==============form=================="<< std::endl
             << "name\t\t: " << f.getName() << std::endl
             << "signed\t\t: " << (f.getSign() ? "TRUE" : "FALSE") << std::endl
             << "signedGrade\t: " << f.getSignedGrade() << std::endl
             << "excuteGrade\t: " << f.getExcuteGrade() << std::endl
             << "==============endl==================" << std::endl;
} 

