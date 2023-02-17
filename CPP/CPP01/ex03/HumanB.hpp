#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
private:
    std::string _name;
    Weapon      *_weapon;
public:
    HumanB();
    HumanB(std::string name);
    HumanB(std::string name, Weapon *weapon);
    ~HumanB();

    void setWeapon(Weapon &weapon);
    void attack();
};

#endif
