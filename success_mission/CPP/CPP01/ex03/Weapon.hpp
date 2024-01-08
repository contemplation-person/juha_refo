#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
private:
    std::string _type;
public:
    Weapon();
    Weapon(std::string weapon);
    std::string getType();
    void setType(std::string type);
};

#endif
