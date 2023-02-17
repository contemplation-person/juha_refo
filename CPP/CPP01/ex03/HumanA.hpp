#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
private:
    Weapon      &_weapon;
    std::string _name;
public:
    HumanA();
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();

    void attack();
};

#endif
