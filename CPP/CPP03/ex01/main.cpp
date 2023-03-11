#include "ScavTrap.hpp"

int main() {

    std::cout << "--------C_a------------ " << std::endl;
    ClapTrap C_a("C");
    C_a.checkValue();

    std::cout << "--------S_a------------ " << std::endl;
    ScavTrap S_a("S_attac");

    S_a.checkValue();
    std::cout << "----------------------- " << std::endl;
    S_a.attack("t"); 
    S_a.takeDamage(0);
    S_a.beRepaired(0);
    std::cout << "----------------------- " << std::endl;
}
