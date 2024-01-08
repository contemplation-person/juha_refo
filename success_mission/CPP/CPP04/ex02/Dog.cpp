#include "Dog.hpp"

Dog::Dog() 
{
    type = "dog";
    std::cout << this->type <<"\t: call default constructor" << std::endl;
    brain = new Brain();
}

Dog::~Dog()
{
    std::cout << this->type << "\t: call destructor" << std::endl;
    delete brain;
}

Dog::Dog(const Dog& dog) 
    : AAnimal(dog)
{ }

Dog& Dog::operator=(const Dog& dog)
{
    if (this != &dog)
    {
        this->type = dog.type;
        *this->brain = *dog.brain;
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "mung mung" << std::endl;
}
