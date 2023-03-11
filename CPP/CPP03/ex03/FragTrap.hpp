
#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
private:

    enum e_point {
        HITPOINT = 100,
        ENERGYPOINT = 100,
        ATTACKDAMAGE = 30
    };

    std::string     name;
    unsigned int    hitPoint;
    unsigned int    energyPoint;
    unsigned int    attackDamage;
public:
    FragTrap();
    FragTrap(std::string str);
    FragTrap(const FragTrap& fragTrap);
    FragTrap& operator=(const FragTrap& fragTrap);
    ~FragTrap();

    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
    void    highFivesGuys(void);
};


#endif
