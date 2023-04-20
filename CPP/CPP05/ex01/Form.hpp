#pragma once
#ifndef __FORM__
#define __FORM__

#include <iostream>
class Bureaucrat;

class Form 
{
public:
    Form();
    Form(const std::string name, const int signedGrade, const int excuteGrade);
    ~Form();

    void                setSign(bool sign);
    int                 getSign();
    int                 getSignedGrade();
    int                 getExcuteGrade();
    void                beSigned(Bureaucrat& bureaucrat);
    const std::string   getName();

    class GradeTooHighException : public std::exception
    {
    public:
        const char * what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char * what() const throw();
    };

private:
    //All these attributes are private, not protected
    const Form& operator=(const Form& form);
    const std::string   _name;
    bool                _sign;
    const int           _signedGrade;
    const int           _excuteGrade;
};

std::ostream& operator<<(std::ostream& o, Form& f);
#endif
