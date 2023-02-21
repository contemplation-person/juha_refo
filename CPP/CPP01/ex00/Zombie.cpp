#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie::Zombie() : _name("") {};
Zombie::Zombie(std::string name) : _name(name) {};
Zombie::~Zombie() { std::cout << this->_name <<" : delete Zombie" << std::endl; };

std::string Zombie::getName() { return (_name); }
void        Zombie::setName(std::string name) { _name = name; }
void        Zombie::announce(void) { std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl; }

