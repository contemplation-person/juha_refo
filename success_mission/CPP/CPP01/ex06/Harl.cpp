#include "Harl.hpp"

void    Harl::debug(void) {
    std::cout << "debug, debug" << std::endl;
}
void    Harl::info(void) {
    std::cout << "info,,, info" << std::endl;
}

void    Harl::warning(void) {
    std::cout << "waring" << std::endl;
}

void    Harl::error(void) {
    std::cout << "error" << std::endl;
}

void    Harl::complain(std::string level) {
    std::string cmd[4] = {"debug", "info", "warning", "error"};
    void (Harl::*f[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    int i = 0;
    while (i < 4) {
        if (!cmd[i].compare(level)) break;
        i++;
    }
    switch (i) {
    case 0: (this->*f[0])();
    case 1: (this->*f[1])();
    case 2: (this->*f[2])();
    case 3: (this->*f[3])();
        break;
    default: std::cout << level << std::endl;
    }
}

