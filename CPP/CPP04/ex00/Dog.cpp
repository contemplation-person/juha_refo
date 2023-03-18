#include "Dog.hpp"

Dog::Dog() 
{
    setType("dog");
    std::cout << this->type <<" : call default constructor" << std::endl;
}
Dog::~Dog()
{
    std::cout << this->type << " : call destructors" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
}

Dog& Dog::operator=(const Dog& dog)
{
   if (this != &dog)
    {
        this->setType(dog.getType());
    }
    return (*this);
}

void Dog::makeSound() 
{
    std::cout << "mung mung" << std::endl;
}
