#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("ClapTrap") {}
ClapTrap::~ClapTrap() {}
ClapTrap::ClapTrap(const ClapTrap& clapTrap) {
    *this = clapTrap;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap) {
    if (this != &clapTrap) this->name = clapTrap.name;
    return (*this);
}


