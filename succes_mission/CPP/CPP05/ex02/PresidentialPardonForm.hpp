#pragma once
#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string name);
	virtual ~PresidentialPardonForm();

	void execute(Bureaucrat const& executor) const;

private:
	PresidentialPardonForm(const PresidentialPardonForm& form);
	const PresidentialPardonForm& operator=(const AForm& form);

};
#endif