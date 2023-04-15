#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>

class Bureaucrat 
{
public:
    Bureaucrat();
    Bureaucrat(std::string name);
    virtual ~Bureaucrat();
    Bureaucrat(const Bureaucrat &copy);
    const Bureaucrat& operator=(const Bureaucrat &copy);

    void		setGrade(const int& grade);
    void		setName(const std::string& name);
    int			getGrade() const;
    std::string getName() const;

private:
    std::string 	_name;
    int      		_grade;
};

#endif
