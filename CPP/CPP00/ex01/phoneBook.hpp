#pragma once
#include "../libCPP/LibCPP.hpp"
#include <iomanip>

class PhoneBook {
    private: 
        typedef struct s_phoneBook {
            int num;
            std::string name;
            std::string firstName;
            std::string phoneNumber;
            std::string secreatMemo;
            std::string nickName;
        } t_phoneBook;

        int cnt;
        t_phoneBook phonebook[8];
        std::string _cmd;

        int findArrayNum() {
            int i = 0;

            while (i < 8) {
                if (this->phonebook[i++].num == 0) return (i);
            }
            return (-1);
        }

        void addPhoneBook() {
            if (cnt < 8) {
                this->cnt++;
            } else {
                for (int i = 0; i < 8; i++) {
                    this->phonebook[i].num--;
                }
            }
            int emptyArrayNum = findArrayNum();

            print("Name : ");
            std::cin >> this->phonebook[emptyArrayNum].name;
            if (std::cin.eof()) exit(0);
            print("first_name : ");
            std::cin >> this->phonebook[emptyArrayNum].firstName;
            if (std::cin.eof()) exit(0);
            print("nick_name : ");
            std::cin >> this->phonebook[emptyArrayNum].nickName;
            if (std::cin.eof()) exit(0);
            print("phone_number : ");
            std::cin >> this->phonebook[emptyArrayNum].phoneNumber;
            if (std::cin.eof()) exit(0);
            print("secreat_memo : ");
            std::cin >> this->phonebook[emptyArrayNum].secreatMemo;
            if (std::cin.eof()) exit(0);
            this->phonebook[emptyArrayNum].num = this->cnt;
        }

        void printPhoneBook(int idx) {
            std::cout << std::setw(10); 
            print(phonebook[idx].num);
            print("|");
            print(phonebook[idx].name);
            print("|");
            print(phonebook[idx].firstName);
            print("|");
            print(phonebook[idx].phoneNumber);
            print("|");
            return ;       
        }

        void searchPhoneBook() {
            if (this->cnt == 0) {
                printEndl("empty phonebook");
                return ;
            }
            int searchNumber;
            print("search number : ");
            std::cin >> searchNumber;
            if (std::cin.eof()) exit(0);
            if (searchNumber > this->cnt) {
                printEndl ("too large");
            } else if (searchNumber < 1) {
                printEndl("too small");
            } else {
                for (int i = 0; i < this->cnt; i++) {
                    if (phonebook[i].num == searchNumber) printPhoneBook(i);
                }
            }
        }

        void exitPhoneBook() {
            printEndl("EXIT");
            exit(0);
        }

    public:
        void _setCmdInit() { 
            std::memset(phonebook, 0, sizeof(t_phoneBook) * 8); 
            this->cnt = 0;
        }

        void _setCmd() {
            print("get cmd : ");
            std::cin >> _cmd;
            if (std::cin.eof()) exit(0);
            if (std::cin.eof()) {
                printEndl("EOF");
                exit(1);
            }
        }

        void doCmd() {
            if (!_cmd.compare("ADD")) addPhoneBook();
            else if (!_cmd.compare("SEARCH")) searchPhoneBook();
            else if (!_cmd.compare ("EXIT")) exitPhoneBook();
            else { printEndl("wrong cmd"); }
        }

};
