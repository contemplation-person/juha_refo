#include "DiamondTrap.hpp"


int main()
{
    // ClapTrap = yello
    // ScavTrap = purple
    // FragTrap = aqua
    // DiamondTrap = green

   	DiamondTrap diamond; //default constructor
    std::cout << std::endl;

    DiamondTrap diamond2("diamond2"); //name constructor
    std::cout << std::endl;

    DiamondTrap diamond3(diamond2); //copy constructor
    std::cout << std::endl;

    diamond = diamond3; //assignation operator
    std::cout << std::endl;


	//hp : fragtrap 100
	//ep : scavtrap 50
	//attack damege : fragtrap 30
	//attack : scavtrap
    diamond.attack("monster"); // call scavtrap's attack
    std::cout << std::endl;
    diamond.takeDamage(50); // call scavtrap's takeDamage
    std::cout << std::endl;
    diamond.guardGate(); //scavtrap
    std::cout << std::endl;
    diamond.highFivesGuys(); //fragtrap
    std::cout << std::endl;
    // diamond.whoAmI(); //diamond + claptrap;
    std::cout << std::endl;
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
