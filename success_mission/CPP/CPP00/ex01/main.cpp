#include "PhoneBook.hpp"
#include <cstring>
#include <cstdlib>

int main() {
    PhoneBook   phoneBook;
    std::string str;

    while (1) {
        std::cout << "ADD | SEARCH | EXIT" << std::endl;
        std::getline(std::cin, str);
        if (isCinErr("wrong cmd")) continue;
        std::cout << "----------------------------------------------------" << std::endl;
        if (!str.compare("ADD")) { phoneBook.setContact(); }
        else if (!str.compare("SEARCH")) {
            std::cout << "====================================================" << std::endl;
            phoneBook.displayContactList();
            std::cout << "====================================================" << std::endl;
            std::cout << "Index : ";
            std::getline(std::cin, str);
            std::cout << "====================================================" << std::endl;
            if (isCinErr("wrong cmd") || str.size() != 1) continue;
            phoneBook.displayContactOne(str[0] - '0' - 1); 
        } else if (!str.compare("EXIT")) {
            exit(1);
        } else {
            std::cout << "wrong input" << std::endl;
        }
        //system("leaks ./phoneBook");
        std::cout << "----------------------------------------------------" << std::endl;
    }
    return (0);
}
