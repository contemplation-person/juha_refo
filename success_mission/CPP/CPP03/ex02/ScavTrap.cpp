#include "ScavTrap.hpp"

ScavTrap::ScavTrap() 
    : ClapTrap("ScavTrap", HITPOINT, ENERGYPOINT, ATTACKDAMAGE) 
{
    std::cout << this->name << " : default" << std::endl;
}

ScavTrap::ScavTrap(std::string s_name) 
    : ClapTrap(s_name, HITPOINT, ENERGYPOINT, ATTACKDAMAGE) 
{
    std::cout << this->name << " : default" << std::endl;
}

ScavTrap::~ScavTrap() 
{ 
    std::cout << this->name << " : distructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) 
    : ClapTrap(scavTrap) 
{ }


ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
    if (this != &scavTrap)
    {
        this->name = scavTrap.name;
        this->hitPoint = scavTrap.hitPoint;
        this->energyPoint = scavTrap.energyPoint;
        this->attackDamage = scavTrap.attackDamage;
    }
    return (*this);
}

void ScavTrap::guardGate()
{
    std::cout << name << " : guard gate mode" <<  std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    
    if (energyPoint == 0 || hitPoint == 0)
    {
        std::cout << this->name << " : empty point" <<std::endl;
        return ;
    }
    std::cout << this->name << " attack " << target << " : " << attackDamage << std::endl;
    energyPoint--;
    std::cout << this->name << " have energy point : " << energyPoint << std::endl;

}
