#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : 
    name("ScavTrap"), 
    hitPoint(HITPOINT), 
    energyPoint(ENERGYPOINT), 
    attackDamage(ATTACKDAMAGE) 
{
    std::cout << "create : " << this->name << std::endl;
}

ScavTrap::ScavTrap(std::string clapName) : 
    name(clapName), 
    hitPoint(HITPOINT), 
    energyPoint(ENERGYPOINT), 
    attackDamage(ATTACKDAMAGE) 
{}

ScavTrap::~ScavTrap() {
    std::cout << "delete : " << this->name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) : ClapTrap() {
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

void    ScavTrap::attack(const std::string& target) {
    if (energyPoint == 0 || hitPoint == 0) {
        std::cout << "empty point" <<std::endl;
        return ;
    }
    std::cout << name << " attack " << target << " : " << attackDamage << std::endl;
    energyPoint--;
    std::cout << name << " have energy point : " << energyPoint << std::endl;
}

void    ScavTrap::takeDamage(unsigned int amount) {
    if (energyPoint == 0 || hitPoint == 0) {
        std::cout << "empty point" <<std::endl;
        return ;
    }
    if (hitPoint < amount) hitPoint = 0;
    else hitPoint -= amount;
    std::cout << "take Damage : " << amount << std::endl;
    std::cout << name << " have hp : " << hitPoint << std::endl;
}

void    ScavTrap::beRepaired(unsigned int amount) {
    if (energyPoint == 0 || hitPoint == 0) {
        std::cout << "empty point" <<std::endl;
        return ;
    }
    if (0 < this->hitPoint && this->hitPoint < 100) {
        hitPoint += amount;
        if (hitPoint > 100) hitPoint = 100;
    }
    energyPoint--;
    std::cout << name << " have energy point : " << energyPoint << std::endl;
}
