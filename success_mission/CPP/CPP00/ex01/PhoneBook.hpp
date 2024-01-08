#pragma once
#include "../libCPP/LibCPP.hpp"
#include "Contact.hpp"

class PhoneBook {
private: 
    Contact          _contact[8];
    unsigned int     _saveIndex;

public:
    PhoneBook();

    void    displayContactOne(int num);
    void    increaseSaveIndex();
    void    setContact();
    void    displayContactList();
};

