#pragma once
#include "../libCPP/LibCPP.hpp"
#include "Contact.hpp"

class PhoneBook {
private: 
    Contact          _contact[8];
    unsigned int     _saveIndex;

public:
    PhoneBook() {_saveIndex = 0;}

    void    increaseSaveIndex();
    Contact getContact(int num);
    void    setContact();
    void    contactAll();
};

