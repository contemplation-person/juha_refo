#pragma once

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
protected:
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
};

std::ostream& operator<<(std::ostream& o, const ScavTrap& scavTrap);

#endif
