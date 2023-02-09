#include "PhoneBook.hpp"
#include <cstring>
#include <cstdlib>

void printIndex(PhoneBook phonebook, std::string strIndex){
    char c; 

    for (int i = 0; i < 8; i++) {
        c = phonebook.getContact(i).getNum() + '0';
        if (c == strIndex[0] && strIndex.size() == 1) {
            phonebook.getContact(i).printAllContact();
            return ; 
        } 
    }
    printEndl("no search idx");
}

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
            phoneBook.contactAll();
            print("Index : ");
            std::cin >> str;
            printEndl("====================================================");
            if (isCinErr("wrong cmd")) continue;
            printIndex(phoneBook, str);
            printEndl("");
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
