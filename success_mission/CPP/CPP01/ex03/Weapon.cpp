#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) { _type = weapon; }
Weapon::Weapon() {}

std::string Weapon::getType() { return (_type); }
void Weapon::setType(std::string type) { _type = type; }
