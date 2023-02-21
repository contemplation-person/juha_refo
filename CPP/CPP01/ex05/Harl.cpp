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

    for (int i = 0; i < 4; i++) {
        switch (cmd[i].compare(level)) {
            case 0: (this->*f[i])();
        }
    }
}

