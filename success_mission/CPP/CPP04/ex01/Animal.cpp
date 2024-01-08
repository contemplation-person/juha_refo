#include "Animal.hpp"

Animal::Animal() 
{
    this->type = "X";
    std::cout << this->type << "\t: call default constructors" << std::endl;
}

Animal::~Animal()
{
    std::cout << this->type << "\t: call destructors" << std::endl;
}

Animal::Animal(const Animal& animal)
{
    *this = animal;    
}

Animal& Animal::operator=(const Animal& animal)
{
    if (this != &animal)
    {
        type = animal.type;
    }
    return (*this);
}

void Animal::setType(std::string type) 
{
    this->type = type;
}

std::string Animal::getType() const 
{
    return this->type;
}

void Animal::makeSound() const { }
