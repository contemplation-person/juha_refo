#pragma once
#ifndef __MATERIA_HPP__
#define __MATERIA_HPP__

#include <iostream>
#include "ICharacter.hpp"

class Materia 
{
protected:
    std::string type;

public:
    Materia();
    virtual ~Materia();
    Materia(const Materia& Materia);
    Materia& operator=(const Materia& Materia);

    Materia(std::string const& type);
    std::string const& getType() const; //Returns the materia type
    virtual Materia* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
