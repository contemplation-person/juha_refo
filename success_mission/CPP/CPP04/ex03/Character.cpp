#include "Character.hpp"

Character::Character() { }
Character::~Character() 
{
    for (int i = 0; i < 4; i++)
    {
        if (materia[i] != NULL)
            delete materia[i];
    }
}

Character::Character(const std::string& name)
    : name(name), idx(0)
{ 
    for(int i = 0; i < 4; i++)
        this->materia[i] = NULL;
}

Character::Character(const Character& character)
{
    *this = character;
}

Character& Character::operator=(const Character& character)
{
    if (this == &character)
    {
        this->idx = character.idx;
        for (int i = 0; i < 4; i++)
            this->materia[i] = character.materia[i];
        this->name = character.name;
    }
    return *this;
}

int  Character::emptyMateria()
{
    for(int i = 0; i < 4; i++)
    {
        if (this->materia[i] != NULL)
        {
            return i;
        }
    }
    return -1;
}

std::string const & Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    int materiaIdx = emptyMateria();

    if (materiaIdx != -1)
    {
        this->materia[materiaIdx] = m->clone();
        idx++;
    }
}

int   Character::findMateria(std::string& str)
{
    for(int i = 0; i < 4; i++)
    {
        if (this->materia[i] != NULL && 
            !(materia[i]->getType().compare(str))
            )
        {
            return i;
        }
    }
    return -1;
}

void Character::unequip(int idx)
{
    if (materia[idx] != NULL)
    {
        delete materia[idx];
        materia[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (materia[idx] != NULL)
    {
        target.equip(materia[idx]->clone());
        delete materia[idx];
    }
}

