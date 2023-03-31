#include "AMateria.hpp"

AMateria::AMateria()
    : type("empty")
{};
AMateria::~AMateria() {};

AMateria::AMateria(const AMateria& aMateria) 
{
    *this = aMateria;
}

AMateria& AMateria::operator=(const AMateria& aMateria)
{
    if (&aMateria != this)
    {
        this->type = aMateria.type;
    }
    return *this;
}

AMateria::AMateria(std::string const& type) 
{
    this->type = type;
}

std::string const& AMateria::getType() const 
{
    return type;
} //Returns the materia type
 
void AMateria::use(ICharacter& target) 
{
    std::string message;

    if (!type.compare("ice"))
    {
        message = "\"* shoots an ice bolt at" + target.getName() + " *\"";
    }
    else if (!type.compare("cure"))
    {
        message = "\"* heals" + target.getName() + "’s wounds *\"";
    }
    else
    {
        return ;
    }
    target.equip(this);
    std::cout << message << std::endl;
}
