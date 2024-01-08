#include "Zombie.hpp"

int main() {
    Zombie z = Zombie("create");
    Zombie *zom = zombieHorde(2, "Arr");
    //std::cout << zom[0].getName() << std::endl;
    delete[] zom;
    //system("leaks Zombie");
    return 0;
}
