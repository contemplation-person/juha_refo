#include "PhoneBook.hpp"
#include <cstring>
#include <cstdlib>

int main() {
    PhoneBook   phoneBook;
    std::string str;

    while (1) {
        printEndl("ADD | SEARCH | EXIT");
        std::cin >> str;
        if (isCinErr("wrong cmd")) continue;
        printEndl("----------------------------------------------------");
        if (!str.compare("ADD")) { phoneBook.setContact(); }
        else if (!str.compare("SEARCH")) {
            printEndl("====================================================");
            phoneBook.displayContactList();
            printEndl("====================================================");
            print("Index : ");
            std::cin >> str;
            if (isCinErr("wrong cmd") || str.size() != 1) continue;
            phoneBook.displayContactOne(str[0] - '0' - 1); 
        } else if (!str.compare("EXIT")) {
            exit(1);
        } else {
            printEndl("wrong input");
        }
        //system("leaks ./phoneBook");
        printEndl("----------------------------------------------------");
    }
    return (0);
}
