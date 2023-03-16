#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
    : ClapTrap()
{
    this->name = "noname";
    std::cout << this->DiamondTrap::name << " : default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string d_name) 
    : ClapTrap(d_name, FragTrap::HITPOINT, HITPOINT, HITPOINT)
{
    this->name = d_name;
    std::cout << name << " : name constructor" << std::endl;
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

