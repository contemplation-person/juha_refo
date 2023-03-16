#include "FragTrap.hpp"

FragTrap::FragTrap() 
    : ClapTrap("FragTrap", HITPOINT, ENERGYPOINT, ATTACKDAMAGE) 
{
    std::cout << this->name << " : default" << std::endl;
}

FragTrap::FragTrap(std::string s_name) 
    : ClapTrap(s_name, HITPOINT, ENERGYPOINT, ATTACKDAMAGE) 
{
    std::cout << this->name << " : default" << std::endl;
}

FragTrap::~FragTrap() 
{ 
    std::cout << this->name << " : distructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap) 
    : ClapTrap(fragTrap) 
{ }


FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
    if (this != &fragTrap)
    {
        this->name = fragTrap.name;
        this->hitPoint = fragTrap.hitPoint;
        this->energyPoint = fragTrap.energyPoint;
        this->attackDamage = fragTrap.attackDamage;
    }
    return (*this);
}

void FragTrap::highFivesGuys()
{
    std::cout << name << " : highfives yeahhhhhh" <<  std::endl;
}
