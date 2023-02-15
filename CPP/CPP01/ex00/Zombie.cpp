#include "Zombie.hpp"
#include <ostream>
#include <string>

Zombie::Zombie() : _name("") {};
Zombie::Zombie(std::string name) : _name(name) {};

std::string Zombie::getName() { return (_name); }
void        Zombie::setName(std::string name) { _name = name; }
void        Zombie::announce(void) { std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl; }

