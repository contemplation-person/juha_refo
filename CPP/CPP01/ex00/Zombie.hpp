#pragma once
#include "../libCPP/LibCPP.hpp"
#include <string>

class Zombie {
private:
    std::string _name;

public:
    Zombie();
    Zombie(std::string name);

    void        setName(std::string name);
    std::string getName(void);
    
    void        announce(void);
};

Zombie*     newZombie(std::string name);
void        randomChump(std::string name);
