#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
    std::cout << "----------------------- " << std::endl;
    F_a.attack("t"); 
    F_a.takeDamage(0);
    F_a.beRepaired(0);
    F_a.highFivesGuys();
    std::cout << "----------------------- " << std::endl;
}
