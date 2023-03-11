#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ScavTrap S_a("ScavTrap_attack");
    ScavTrap S_b("ScavTrap_damage");
    ScavTrap S_c("ScavTrap_repaire");

    FragTrap F_d("FragTrap_attack");
    FragTrap F_e("FragTrap_damage");
    FragTrap F_f("FragTrap_repaire");
    
    F_d.highFivesGuys();

}
