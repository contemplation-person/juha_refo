#include "Sed.hpp"
#include <fstream>
#include <string>

Sed::Sed(std::string fileName, std::string s1, std::string s2) : _fileName(fileName), _s1(s1), _s2(s2) { }
Sed::Sed() : _fileName(""), _s1(""), _s2("") { }
Sed::~Sed() {}

#include <iostream>
void    Sed::replace() {
    std::ifstream   ifs;
    std::ofstream   ofs;
    std::string     str;

    ifs.open(_fileName);
    if (!ifs.is_open()) return ;
    ofs.open(_fileName.append(".replace"));
    if (!ofs.is_open()) return ;

    int pos = 0;

    while (!ifs.eof()) {
        std::getline(ifs, str);
        // replace code
        pos = 0;
        while (str.find(_s1, pos) != std::string::npos) {
            pos = str.find(_s1, pos);
            //std::cout << pos << std::endl;
            str.erase(pos, _s1.size());
            str.insert(pos, _s2);
            pos += _s1.size() < _s2.size() ? _s2.size() - _s1.size() : _s2.size();
        }
        ofs << str;
        if (!ifs.eof()) ofs << std::endl;
    }
    ofs.close();
    ifs.close();
}
