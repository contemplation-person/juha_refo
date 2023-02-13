#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
    Zombie *tmp = new Zombie;

    tmp->setName(name);
    return (tmp);
}
