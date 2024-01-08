#pragma once
#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string name);
	virtual ~RobotomyRequestForm();

    void execute(Bureaucrat const& executor) const;
private:
	RobotomyRequestForm(const RobotomyRequestForm& form);
	const RobotomyRequestForm& operator=(const AForm& form);

};
#endif