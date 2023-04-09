#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>

class Bureaucrat
{
public:
	Bureaucrat(std::string name);
	virtual ~Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	const Bureaucrat& operator=(const Bureaucrat &copy);

	void		setGrade(int grade);
	void		setName(std::string name);
	int			getGrade();
	std::string getName();


private:
	Bureaucrat();
	std::string 	_name;
	int 			_grade;
};


#endif