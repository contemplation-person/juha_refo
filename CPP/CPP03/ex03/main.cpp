#include "DiamondTrap.hpp"

int main() 
{
    std::cout << "--------C_a------------ " << std::endl;
    ClapTrap C_a("C");
    C_a.checkValue();

    std::cout << "--------S_a------------ " << std::endl;
    ScavTrap S_a("S_attac");

    S_a.checkValue();
    std::cout << "--------F_a------------ " << std::endl;
    FragTrap F_a("F_attac");

    F_a.checkValue();
    std::cout << "--------F_a------------ " << std::endl;
    DiamondTrap D_a("diamond");

    D_a.checkValue();
    std::cout << "----------------------- " << std::endl;
    D_a.attack("t"); 
    D_a.takeDamage(0);
    D_a.beRepaired(0);
    D_a.highFivesGuys();
    std::cout << "----------------------- " << std::endl;
}
