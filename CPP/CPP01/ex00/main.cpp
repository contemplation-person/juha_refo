#include "Zombie.hpp"

int main() {
    Zombie *zom;

    zom = newZombie("newzom");
    zom->announce();
    randomChump("random");
    delete zom;
    return 0;
}
