#pragma once
#ifndef __CHARACTER__
#define __CHARACTER__

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character : public ICharacter
{
public:
    Character();
    Character(const std::string& name);
    ~Character();
    Character(const Character& character);
    Character& operator=(const Character& character);
    
    virtual std::string const & getName() const;
    virtual void  equip(AMateria* m);
    virtual void  unequip(int idx);
    virtual void  use(int idx, ICharacter& target);
    virtual int   emptyMateria();
    virtual int   findMateria(std::string& str);
protected:
    int idx;
    const AMateria* materia[4];
    std::string name;

private:
};

#endif
