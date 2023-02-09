#pragma once
#include "../libCPP/LibCPP.hpp"
#include "Contact.hpp"

class PhoneBook {
private: 
    Contact          _contact[8];
    unsigned int     _saveIndex;

public:
    PhoneBook();

    void    printAllContact();
    void    increaseSaveIndex();
    Contact getContact(int num);
    void    setContact();
    void    contactAll();
};

