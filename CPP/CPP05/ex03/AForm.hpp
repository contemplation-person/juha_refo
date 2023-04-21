#pragma once
#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <iostream>
class Bureaucrat;

class AForm 
{
public:
    AForm();
    AForm(const std::string name, const int signedGrade, const int excuteGrade);
    virtual ~AForm();

    void                setSign(bool sign);
    int                 getSign() const;
    int                 getSignedGrade() const;
    int                 getExcuteGrade() const;
    void                beSigned(Bureaucrat& bureaucrat);
    const std::string   getName() const;
    virtual void        execute(Bureaucrat const& executor) const = 0;

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
    AForm(const AForm& copy);
    const AForm& operator=(const AForm& form);
    const std::string   _name;
    bool                _sign;
    const int           _signedGrade;
    const int           _excuteGrade;
};

std::ostream& operator<<(std::ostream& o, AForm& f);
#endif
