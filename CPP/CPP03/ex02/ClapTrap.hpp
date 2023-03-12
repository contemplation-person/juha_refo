#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap 
{
private:
    enum 
    {
        HITPOINT = 10,
        ENERGYPOINT = 10,
        ATTACKDAMAGE = 0
    };

protected:
    std::string     name;
    unsigned int    hitPoint;
    unsigned int    energyPoint;
    unsigned int    attackDamage;
public:
    ClapTrap();
    ClapTrap(std::string str);
    ClapTrap(std::string str, int hp, int ep, int ad);
    ClapTrap(const ClapTrap& clapTrap);
    ClapTrap& operator=(const ClapTrap& clapTrap);
    ~ClapTrap();

    void    attack(const std::string& target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);
    void    checkValue();
};


#endif
