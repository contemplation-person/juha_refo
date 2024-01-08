#include "Zombie.hpp"

int main() {
    Zombie *zom;

    randomChump("random");
    zom = newZombie("newzom");
    zom->announce();
    delete zom;
//    system("leaks Zombie");
    return 0;
}
