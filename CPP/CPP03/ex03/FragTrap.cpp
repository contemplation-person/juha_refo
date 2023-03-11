#include "FragTrap.hpp"

FragTrap::FragTrap() : 
    name("FragTrap"), 
    hitPoint(HITPOINT), 
    energyPoint(ENERGYPOINT), 
    attackDamage(ATTACKDAMAGE) 
{
    std::cout << "create : " << this->name << std::endl;
}

FragTrap::FragTrap(std::string clapName) : 
    name(clapName), 
    hitPoint(HITPOINT), 
    energyPoint(ENERGYPOINT), 
    attackDamage(ATTACKDAMAGE) 
{}

FragTrap::~FragTrap() {
    std::cout << "delete : " << this->name << std::endl;
}

FragTrap::FragTrap(const FragTrap& fragTrap) : ClapTrap() {
    *this = fragTrap;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap) {
    if (this != &fragTrap) {
        this->name = fragTrap.name;
        this->hitPoint = fragTrap.hitPoint;
        this->energyPoint = fragTrap.energyPoint;
        this->attackDamage = fragTrap.attackDamage;
    }
    return (*this);
}

void    FragTrap::attack(const std::string& target) {
    if (energyPoint == 0 || hitPoint == 0) {
        std::cout << "empty point" <<std::endl;
        return ;
    }
    std::cout << name << " attack " << target << " : " << attackDamage << std::endl;
    energyPoint--;
    std::cout << name << " have energy point : " << energyPoint << std::endl;
}

void    FragTrap::takeDamage(unsigned int amount) {
    if (energyPoint == 0 || hitPoint == 0) {
        std::cout << "empty point" <<std::endl;
        return ;
    }
    if (hitPoint < amount) hitPoint = 0;
    else hitPoint -= amount;
    std::cout << "take Damage : " << amount << std::endl;
    std::cout << name << " have hp : " << hitPoint << std::endl;
}

void    FragTrap::beRepaired(unsigned int amount) {
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

void    FragTrap::highFivesGuys(void) {
    std::cout << "hifive!!!!!!!!yeeeeeeeeh!!" << std::endl;
} 
