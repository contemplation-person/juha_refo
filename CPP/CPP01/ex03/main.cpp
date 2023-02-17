#include "HumanA.hpp"
#include "HumanB.hpp"

#include <iostream>
#include <string>

int main()
{
    {
        Weapon club = Weapon("crude spiked club1");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club2");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club3");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club4");
        jim.attack();
    }

/*
    std::cout << "* etc" << std::endl;
    Weapon club = Weapon("crude spiked club1");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club2");
    bob.attack();

    club = Weapon("crude spiked club3");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club4");
    jim.attack();
*/
//    system("leaks Human");
    return 0;
}
