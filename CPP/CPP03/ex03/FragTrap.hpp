#pragma once

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
    enum
    {
        HITPOINT = 100,
        ENERGYPOINT = 100,
        ATTACKDAMAGE = 30
    };

public:
    FragTrap();
    FragTrap(std::string str);
    FragTrap(const FragTrap& fragTrap);
    FragTrap& operator=(const FragTrap& fragTrap);
    ~FragTrap();
    void highFivesGuys();
};

std::ostream& operator<<(std::ostream& o, FragTrap& fragTrap);

#endif
