#include "Animal.hpp"

Animal::Animal() 
{
    this->type = "X";
    std::cout << this->type << " : call default constructor" << std::endl;
}

Animal::~Animal()
{
    std::cout << "call destructors" << std::endl;
}

Animal::Animal(const Animal& animal)
{
    *this = animal;    
}

Animal& Animal::operator=(const Animal& animal)
{
   if (this != &animal)
    {
        this->setType(animal.getType());
    }
    return (*this);
}

inline void Animal::setType(std::string type)
{
    this->type = type;
}

inline std::string Animal::getType() const 
{
    return this->type;
}

