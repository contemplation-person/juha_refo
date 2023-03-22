#pragma once

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
    enum
    {
        HITPOINT = 100,
        ENERGYPOINT = 50,
        ATTACKDAMAGE = 20
    };

public:
    ScavTrap();
    ScavTrap(std::string str);
    ScavTrap(const ScavTrap& scavTrap);
    ScavTrap& operator=(const ScavTrap& scavTrap);
    ~ScavTrap();
    void guardGate();
    void attack(const std::string& target);
};

#endif
