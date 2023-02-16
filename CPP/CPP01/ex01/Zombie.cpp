#include "Zombie.hpp"
#include <ostream>
#include <string>

Zombie::Zombie() : _name("") {std::cout << "arr create" << std::endl; };
Zombie::Zombie(std::string name) : _name(name) { std::cout << _name << " : basic make" << std::endl;};
Zombie::~Zombie() { std::cout << this->_name <<" : delete Zombie" << std::endl; };

std::string Zombie::getName() { return (_name); }
void        Zombie::setName(std::string name) { _name = name; }
void        Zombie::announce(void) { std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl; }

