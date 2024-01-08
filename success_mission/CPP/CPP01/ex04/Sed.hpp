#pragma once
#ifndef SED_HPP
#define SED_HPP

#include <string>

class Sed {
private:
    std::string _fileName;   
    std::string _s1;   
    std::string _s2;   

public:
    Sed(std::string fileName, std::string s1, std::string s2);
    Sed();
    ~Sed();

    void    replace();
};

#endif
