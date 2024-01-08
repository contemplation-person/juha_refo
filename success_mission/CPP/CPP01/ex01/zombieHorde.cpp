#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie *zombie = new Zombie[N];
    for (int i = 0; i < N; i++) {
        zombie[i].setName(name);
    }
    //zombie[0].setName("123");
    return (zombie);
}
