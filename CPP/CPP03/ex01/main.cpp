#include "ScavTrap.hpp"

int main() {
    ScavTrap attack("ScavTrap_attack");
    ScavTrap damage("ScavTrap_damage");
    ScavTrap repaire("ScavTrap_repaire");

    for (int i = 0; i < 11; i++) {
        attack.attack("aaaa");
        std::cout << "============" << std::endl;
        damage.takeDamage(1);
        std::cout << "============" << std::endl;
        if (i == 8) {
            repaire.beRepaired(1);
            std::cout << "============" << std::endl;
        } 
    }
    for (int i = 0; i < 11; i++) {
        repaire.takeDamage(1);
        std::cout << "============" << std::endl;
        repaire.attack("ttt");
        std::cout << "============" << std::endl;
        repaire.beRepaired(1);
        std::cout << "============" << std::endl;
    }
}
