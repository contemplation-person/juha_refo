#pragma once
#include "../libCPP/LibCPP.hpp"

class Zombie {
private:
    std::string _name;

public:
    Zombie();

    void        setName(std::string name);
    std::string getName(void);
    
    void        announce(void);
    Zombie*     newZombie(std::string name);
    void        randomChump(std::string name);
};
