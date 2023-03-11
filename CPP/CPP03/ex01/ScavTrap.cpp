#include "ScavTrap.hpp"

ScavTrap::ScavTrap() 
    : ClapTrap("ScavTrap", HITPOINT, ENERGYPOINT, ATTACKDAMAGE) 
{
    std::cout << this->name << " : default" << std::endl;
}

ScavTrap::ScavTrap(std::string name) 
    : ClapTrap(name, HITPOINT, ENERGYPOINT, ATTACKDAMAGE) 
{
    std::cout << this->name << " : default" << std::endl;
}

ScavTrap::~ScavTrap() 
{ 
    std::cout << this->name << " : distructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) 
{
    *this = scavTrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap) {
    if (this != &scavTrap) {
        this->name = scavTrap.name;
        this->hitPoint = scavTrap.hitPoint;
        this->energyPoint = scavTrap.energyPoint;
        this->attackDamage = scavTrap.attackDamage;
    }
    return (*this);
}

