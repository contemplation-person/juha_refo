#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
    : ClapTrap("_clap_name", FragTrap::HITPOINT, ScavTrap::ENERGYPOINT, FragTrap::ATTACKDAMAGE)
{
    this->name = "dia";
    std::cout << this->DiamondTrap::name << " : default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string d_name) 
    : ClapTrap(d_name + "_clap_name", FragTrap::HITPOINT, ScavTrap::ENERGYPOINT, FragTrap::ATTACKDAMAGE)
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

void DiamondTrap::whoAmI() 
{
    std::cout << this->name << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}
