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

    void execute(Bureaucrat const& executor) const;
private:
    ShrubberyCreationForm(const ShrubberyCreationForm& form);
    const ShrubberyCreationForm& operator=(const AForm& form);
};
#endif
