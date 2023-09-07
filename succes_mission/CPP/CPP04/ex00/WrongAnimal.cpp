#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() 
{
    this->type = "X";
    std::cout << this->type << " : call default constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << this->type << "call destructors" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& animal)
{
    *this = animal;    
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& animal)
{
    if (this != &animal)
    {
        this->setType(animal.getType());
    }
    return (*this);
}

inline void WrongAnimal::setType(std::string type)
{
    this->type = type;
}

inline std::string WrongAnimal::getType() const 
{
    return this->type;
}

void WrongAnimal::makeSound() const { 
    std::cout << "wrong" << std::endl;
}
