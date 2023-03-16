#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
    : name("ClapTrap"), hitPoint(HITPOINT), energyPoint(ENERGYPOINT), attackDamage(ATTACKDAMAGE) 
{
    std::cout << "create : " << this->name << std::endl;
}

ClapTrap::ClapTrap(std::string clapName) 
    : name(clapName), hitPoint(HITPOINT), energyPoint(ENERGYPOINT), attackDamage(ATTACKDAMAGE) 
{
    std::cout << "create : " << this->name << std::endl;
}

ClapTrap::ClapTrap(std::string clapName, int hp, int ep, int ad) : 
    name(clapName), hitPoint(hp), energyPoint(ep), attackDamage(ad) 
{
    std::cout << "create : " << this->name << std::endl;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "delete : " << this->name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap) 
{
    *this = clapTrap;
}

#define Y "\033[33m"
#define N "\033[0m"
std::ostream& operator<<(std::ostream& o, const ClapTrap& clapTrap)
{
    o << Y << clapTrap << N;
    return o;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap) 
{
    if (this != &clapTrap)
    {
        this->name = clapTrap.name;
        this->hitPoint = clapTrap.hitPoint;
        this->energyPoint = clapTrap.energyPoint;
        this->attackDamage = clapTrap.attackDamage;
    }
    return (*this);
}

void    ClapTrap::attack(const std::string& target) 
{
    if (energyPoint == 0 || hitPoint == 0)
    {
        std::cout << "empty point" <<std::endl;
        return ;
    }
    std::cout << this->name << " attack " << target << " : " << attackDamage << std::endl;
    energyPoint--;
    std::cout << this->name << " have energy point : " << energyPoint << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount) 
{
    if (energyPoint == 0 || hitPoint == 0)
    {
        std::cout << "empty point" <<std::endl;
        return ;
    }
    if (hitPoint < amount) hitPoint = 0;
    else hitPoint -= amount;
    std::cout << "take Damage : " << amount << std::endl;
    std::cout << this->name << " have hp : " << hitPoint << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount) 
{
    if (energyPoint == 0 || hitPoint == 0)
    {
        std::cout << "empty point" <<std::endl;
        return ;
    }
    if (0 < this->hitPoint && this->hitPoint < HITPOINT)
    {
        hitPoint += amount;
        if (hitPoint > HITPOINT) hitPoint = HITPOINT;
    }
    energyPoint--;
    std::cout << this->name << " have energy point : " << energyPoint << std::endl;
}

void    ClapTrap::checkValue() 
{
    std::cout << "this name : " << this->name << ", " \
    << "this hitPoint : " << this->hitPoint << ", " \
    << "this energyPoint : " << this->energyPoint << ", " \
    << "this attackDamage : " << this->attackDamage << std::endl;
}

