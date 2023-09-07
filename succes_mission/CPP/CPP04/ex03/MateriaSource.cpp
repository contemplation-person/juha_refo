#include "MateriaSource.hpp"
#include "Materia.hpp"

MateriaSource::MateriaSource()
    : idx(0)
{
    materia = new Materia[4];
}

MateriaSource::~MateriaSource() 
{
    delete [] materia;
}

MateriaSource(const MateriaSource& src)
{

}

MateriaSource& operator=(const MateriaSource& src)
{

}

void MateriaSource::learnMateria(AMateria*);
AMateria* MateriaSource::createMateria(std::string const & type);
