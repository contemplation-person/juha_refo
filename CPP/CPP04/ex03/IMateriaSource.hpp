#pragma once
#ifndef __IMATERIA_SOURCE_HPP__
#define __IMATERIA_SOURCE_HPP__

#include <iostream>
class AMateria;

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
