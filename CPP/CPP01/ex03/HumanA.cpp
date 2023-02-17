#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon), _name(name) {};
HumanA::~HumanA(){ std::cout << "done"<< std::endl; };

void  HumanA::attack() {
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
