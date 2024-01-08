#pragma once 
#ifndef __MATERIA_SOURCE_HPP__
#define __MATERIA_SOURCE_HPP__

#include "IMateriaSource.hpp"
class AMateria;

class MateriaSource : public IMateriaSource
{
public:
    MateriaSource();
    virtual ~MateriaSource();
    MateriaSource(const MateriaSource& src);
    MateriaSource& operator=(const MateriaSource& src);

    virtual void learnMateria(AMateria*);
    virtual AMateria* createMateria(std::string const & type);

protected:
    int idx;
    const AMateria* materia;
};

#endif
