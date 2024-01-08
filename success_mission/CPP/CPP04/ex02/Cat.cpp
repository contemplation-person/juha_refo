#include "Cat.hpp"

Cat::Cat() 
{
    type = "cat";
    std::cout << this->type << "\t: call default constructor" << std::endl;
    brain = new Brain();
}

Cat::~Cat()
{
    std::cout << type  << "\t: call destructor" << std::endl;
    delete brain;
}

Cat::Cat(const Cat& cat) 
    : AAnimal(cat)
{
    *this = cat;
}

Cat& Cat::operator=(const Cat& cat)
{
    if (this != &cat)
    {
        this->type = cat.type;
        *this->brain = *cat.brain;
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "yaong" << std::endl;
}

