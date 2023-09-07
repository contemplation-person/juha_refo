#include "DiamondTrap.hpp"


int main()
{
    DiamondTrap d("hh");

    d.checkValue();
    d.whoAmI();
    d.attack("scaveTrap");
}
// #include "DiamondTrap.hpp"

// #define Y "\033[33m"
// #define B "\033[34m"
// #define G "\033[32m"
// #define R "\033[31m"
// #define N "\033[0m"





// int main() 
// {
    
//     std::cout << R << "--------C_a------------ " << std::endl;
//     ClapTrap C_a("C");
//     C_a.checkValue();
//     std::cout << N;

//     std::cout << Y << "--------S_a------------ " << std::endl;
//     ScavTrap S_a("S");
//     S_a.checkValue();
//     std::cout << N;

//     std::cout << B << "--------F_a------------ " << std::endl;
//     FragTrap F_a("F");
//     F_a.checkValue();
//     std::cout << N;

//     std::cout << Y << "--------S_a------------ " << std::endl;
//     S_a.checkValue();
//     std::cout << N;

//     std::cout << G << "--------D_a------------ " << std::endl;
//     DiamondTrap D_a("Dia");
//     D_a.checkValue();
//     std::cout << N;

//     std::cout << "----------------------- " << std::endl;
//     D_a.attack("t"); 
//     D_a.takeDamage(0);
//     D_a.beRepaired(0);
//     D_a.highFivesGuys();
//     std::cout << "----------------------- " << std::endl;
// }
