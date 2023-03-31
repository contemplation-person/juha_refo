#pragma once
#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include <iostream>
#include "AMateria.hpp"

class AMateria;

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
