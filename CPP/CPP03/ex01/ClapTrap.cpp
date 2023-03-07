#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("ClapTrap"), hitPoint(10), energyPoint(10), attackDamage(0) {
    std::cout << "create : " << this->name << std::endl;
}
ClapTrap::ClapTrap(std::string clapName) : name(clapName), hitPoint(10), energyPoint(10), attackDamage(0) {}
ClapTrap::~ClapTrap() {
    std::cout << "delete : " << this->name << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& clapTrap) {
    *this = clapTrap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap) {
    if (this != &clapTrap) {
        this->name = clapTrap.name;
        this->hitPoint = clapTrap.hitPoint;
        this->energyPoint = clapTrap.energyPoint;
        this->attackDamage = clapTrap.attackDamage;
    }
    return (*this);
}

void    ClapTrap::attack(const std::string& target) {
    if (energyPoint == 0 || hitPoint == 0) {
        std::cout << "empty point" <<std::endl;
        return ;
    }
    std::cout << name << " attack " << target << " : " << attackDamage << std::endl;
    energyPoint--;
    std::cout << name << " have energy point : " << energyPoint << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (energyPoint == 0 || hitPoint == 0) {
        std::cout << "empty point" <<std::endl;
        return ;
    }
    if (hitPoint < amount) hitPoint = 0;
    else hitPoint -= amount;
    std::cout << "take Damage : " << amount << std::endl;
    std::cout << name << " have hp : " << hitPoint << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoint == 0 || hitPoint == 0) {
        std::cout << "empty point" <<std::endl;
        return ;
    }
    if (0 < this->hitPoint && this->hitPoint < 10) {
        hitPoint += amount;
        if (hitPoint > 10) hitPoint = 10;
    }
    energyPoint--;
    std::cout << name << " have energy point : " << energyPoint << std::endl;
}
