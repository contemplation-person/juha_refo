#include "AAnimal.hpp"

AAnimal::AAnimal() 
{
    this->type = "X";
    std::cout << this->type << "\t: call default constructors" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << this->type << "\t: call destructors" << std::endl;
}

AAnimal::AAnimal(const AAnimal& animal)
{
    *this = animal;    
}

AAnimal& AAnimal::operator=(const AAnimal& animal)
{
    if (this != &animal)
    {
        type = animal.type;
    }
    return (*this);
}

