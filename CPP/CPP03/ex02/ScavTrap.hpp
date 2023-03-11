
#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:

    enum e_point {
        HITPOINT = 100,
        ENERGYPOINT = 50,
        ATTACKDAMAGE = 20
    };

    std::string     name;
    unsigned int    hitPoint;
    unsigned int    energyPoint;
    unsigned int    attackDamage;
public:
    ScavTrap();
    ScavTrap(std::string str);
    ScavTrap(const ScavTrap& scavTrap);
    ScavTrap& operator=(const ScavTrap& scavTrap);
    ~ScavTrap();

    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
};


#endif
