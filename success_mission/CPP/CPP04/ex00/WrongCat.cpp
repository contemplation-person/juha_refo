#include "WrongCat.hpp"

WrongCat::WrongCat() 
{
    setType("cat");
    std::cout << this->type << " : call default constructor" << std::endl;
}
WrongCat::~WrongCat()
{
    std::cout << getType()  << " : call destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& cat) 
    : WrongAnimal(cat)
{ }

WrongCat& WrongCat::operator=(const WrongCat& cat)
{
   if (this != &cat)
    {
        this->setType(cat.getType());
    }
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "yaong" << std::endl;
}
