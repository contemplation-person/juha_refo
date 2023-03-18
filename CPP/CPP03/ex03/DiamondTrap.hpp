#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string name;
    enum
    {
        HITPOINT = 100,
        ENERGYPOINT = 100,
        ATTACKDAMAGE = 30
    };

public:
    DiamondTrap();
    DiamondTrap(std::string str);
    DiamondTrap(const DiamondTrap& diamondTrap);
    DiamondTrap& operator=(const DiamondTrap& diamondTrap);
    void whoAmI();
    void attack(const std::string &target);
    ~DiamondTrap();
};

#endif
