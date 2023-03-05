#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap {
private:
    std::string name;
    int         hitPoint;
    int         energyPoint;
    int         attackDamage;
public:
    ClapTrap();
    ClapTrap(const ClapTrap& clapTrap);
    ClapTrap& operator=(const ClapTrap& clapTrap);
    ~ClapTrap();
};


#endif
