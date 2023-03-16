#include "DiamondTrap.hpp"
#include "FragTrap.hpp"

DiamondTrap::DiamondTrap() 
    : FragTrap("dia")
{
    std::cout << this->DiamondTrap::name << " : default" << std::endl;
}

DiamondTrap::DiamondTrap(std::string d_name) 
    : FragTrap(d_name)
{
    std::cout << this->name << " : default" << std::endl;
}

DiamondTrap::~DiamondTrap() 
{ 
    std::cout << this->name << " : distructor" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) 
    : ClapTrap(diamondTrap),FragTrap(diamondTrap), ScavTrap(diamondTrap)
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

