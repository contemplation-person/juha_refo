
#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"

class DiamondTrap : public ClapTrap, public ScavTrap {
private:

    std::string     name;
    unsigned int    hitPoint;
    unsigned int    energyPoint;
    unsigned int    attackDamage;
public:
    DiamondTrap();
    DiamondTrap(std::string str);
    DiamondTrap(const DiamondTrap& diamondTrap);
    DiamondTrap& operator=(const DiamondTrap& diamondTrap);
    ~DiamondTrap();

    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
};


#endif
