#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
    : name("Dia"), ClapTrap("DiamondTrap", HITPOINT, ENERGYPOINT, ATTACKDAMAGE) 
{
    std::cout << this->name << " : default" << std::endl;
}

DiamondTrap::DiamondTrap(std::string d_name) 
    : name(d_name), ClapTrap("null", HITPOINT, ENERGYPOINT, ATTACKDAMAGE) 
{
    std::cout << this->name << " : default" << std::endl;
}

DiamondTrap::~DiamondTrap() 
{ 
    std::cout << this->name << " : distructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) 
    : ClapTrap(diamondTrap) 
{ }

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
    if (this != &diamondTrap)
    {
        this->name = diamondTrap.name;
        this->hitPoint = diamondTrap.hitPoint;
        this->energyPoint = diamondTrap.energyPoint;
        this->attackDamage = diamondTrap.attackDamage;
    }
    return (*this);
}

