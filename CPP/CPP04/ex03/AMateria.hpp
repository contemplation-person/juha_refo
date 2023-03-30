#pragma once
#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "Character.hpp"
class ICharacter;

class AMateria 
{
private:
    AMateria();
protected:
    std::string type;

public:
    virtual ~AMateria();
    AMateria(const AMateria& aMateria);
    AMateria& operator=(const AMateria& aMateria);

    AMateria(std::string const& type);
    std::string const& getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
