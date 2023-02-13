#include "Zombie.hpp"
#include <ostream>
#include <string>

Zombie::Zombie() : _name("") {};

void        Zombie::setName(std::string name) { _name = name; }
std::string Zombie::getName() { return (_name); }
void        Zombie::announce(void) { std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl; }

