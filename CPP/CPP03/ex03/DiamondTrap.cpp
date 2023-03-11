#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : 
    name("DiamondTrap"), 
    hitPoint(HITPOINT), 
    energyPoint(ENERGYPOINT), 
    attackDamage(ATTACKDAMAGE) 
{
    std::cout << "create : " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(std::string clapName) : 
    name(clapName), 
    hitPoint(HITPOINT), 
    energyPoint(ENERGYPOINT), 
    attackDamage(ATTACKDAMAGE) 
{}

DiamondTrap::~DiamondTrap() {
    std::cout << "delete : " << this->name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap) : ClapTrap() {
    *this = diamondTrap;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap) {
    if (this != &diamondTrap) {
        this->name = diamondTrap.name;
        this->hitPoint = diamondTrap.hitPoint;
        this->energyPoint = diamondTrap.energyPoint;
        this->attackDamage = diamondTrap.attackDamage;
    }
    return (*this);
}

void    DiamondTrap::attack(const std::string& target) {
    if (energyPoint == 0 || hitPoint == 0) {
        std::cout << "empty point" <<std::endl;
        return ;
    }
    std::cout << name << " attack " << target << " : " << attackDamage << std::endl;
    energyPoint--;
    std::cout << name << " have energy point : " << energyPoint << std::endl;
}

void    DiamondTrap::takeDamage(unsigned int amount) {
    if (energyPoint == 0 || hitPoint == 0) {
        std::cout << "empty point" <<std::endl;
        return ;
    }
    if (hitPoint < amount) hitPoint = 0;
    else hitPoint -= amount;
    std::cout << "take Damage : " << amount << std::endl;
    std::cout << name << " have hp : " << hitPoint << std::endl;
}

void    DiamondTrap::beRepaired(unsigned int amount) {
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
