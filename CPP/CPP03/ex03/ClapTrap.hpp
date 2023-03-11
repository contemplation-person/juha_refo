#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap {
private:

    enum e_point {
        HITPOINT = 10,
        ENERGYPOINT = 10,
        ATTACKDAMAGE = 0
    };

    std::string     name;
    unsigned int    hitPoint;
    unsigned int    energyPoint;
    unsigned int    attackDamage;
public:
    ClapTrap();
    ClapTrap(std::string str);
    ClapTrap(const ClapTrap& clapTrap);
    ClapTrap& operator=(const ClapTrap& clapTrap);
    ~ClapTrap();

    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
};


#endif
