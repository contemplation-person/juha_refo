#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {};
HumanB::HumanB(std::string name, Weapon *weapon) : _name(name), _weapon(weapon) {};

HumanB::~HumanB(){ std::cout << "done"<< std::endl; };

void    HumanB::setWeapon(Weapon &weapon) {
    _weapon = &weapon;
}

void  HumanB::attack() {
    std::cout << _name << " attacks with their ";
    if (!_weapon)
        std::cout << _weapon->getType() << std::endl;
    else
        std::cout << std::endl;
}
