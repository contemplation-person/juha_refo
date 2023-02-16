#include "Zombie.hpp"

int main() {
    
    Zombie *zom = zombieHorde(2, "hello");
    //std::cout << zom[0].getName() << std::endl;
    delete[] zom;
    //system("leaks Zombie");
    return 0;
}
