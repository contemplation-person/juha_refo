#pragma once
#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "AForm.hpp"

class Form;
class Intern
{
public:
	Intern();
	virtual ~Intern();

	AForm *makeForm(std::string formName, std::string target);
private:
	Intern(const Intern &copy);
	Intern &operator=(const Intern &copy);
};

#endif