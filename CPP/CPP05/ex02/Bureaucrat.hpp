#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
class AForm;
class Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(std::string name);
    virtual ~Bureaucrat();
    Bureaucrat(const Bureaucrat &copy);
    const Bureaucrat& operator=(const Bureaucrat &copy);

    void	    	setGrade(const int& grade);
    void    		setName(const std::string& name);
    int 			getGrade() const;
    std::string     getName() const;
    void            increment();
    void            decrement();
    void            signForm(AForm& form);
    void            executeForm(AForm const & form);

    class GradeTooHighException : public std::exception{
    public:
        const char *what() const throw();
    };

    class GradeTooLowException: public std::exception{
    public:
        const char *what() const throw();
    };
private:
    std::string 	_name;
    int      		_grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);
#endif
