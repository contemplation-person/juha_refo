#pragma once
#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string name);
    virtual ~ShrubberyCreationForm();

    virtual void beSigned(Bureaucrat& bureaucrat);
private:
    const ShrubberyCreationForm& operator=(const AForm& form);

};
#endif
