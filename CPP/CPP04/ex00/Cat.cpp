#include "Cat.hpp"

Cat::Cat() 
{
    setType("cat");
    std::cout << this->type << " : call default constructor" << std::endl;
}
Cat::~Cat()
{
    std::cout << getType() << " : call destructor" << std::endl;
}

Cat::Cat(const Cat& cat) 
    : Animal(cat)
{ }

Cat& Cat::operator=(const Cat& cat)
{
   if (this != &cat)
    {
        this->setType(cat.getType());
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "yaong" << std::endl;
}
