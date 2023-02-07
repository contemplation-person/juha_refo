#include "PhoneBook.hpp"

int main() {
    PhoneBook phoneBook;
    while (1) {
        printEndl("ADD | SEARCH | EXIT");
        phoneBook._setCmd();
        printEndl("----------------------------------------------------");
        phoneBook.doCmd();
//        phoneBook.display();
        printEndl("----------------------------------------------------");
    }
    return (0);
}
