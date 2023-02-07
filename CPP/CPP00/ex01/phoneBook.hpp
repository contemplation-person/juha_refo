#pragma once
#include "../libCPP/LibCPP.hpp"
#include "Contact.hpp"

class PhoneBook {
private: 
    Contact _contact[8];
public:
    void _setCmd();
    void doCmd();
};
