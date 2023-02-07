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
        t_phoneBook phoneBook[8];
        std::string _cmd;

        int findArrayNum() {
            int i = 0;

            while (i < 8) {
                if (this->phoneBook[i].num == 0) return (i);
                i++;
            }
            return (-1);
        }

        void addPhoneBook() {
            if (cnt == 8) {
                for (int i = 0; i < 8; i++) {
                    this->phoneBook[i].num--;
                }
            }
            int emptyArrayNum = findArrayNum();

            print("Name : ");
            std::cin >> this->phoneBook[emptyArrayNum].name;
            if (std::cin.eof()) exit(0);
            print("first_name : ");
            std::cin >> this->phoneBook[emptyArrayNum].firstName;
            if (std::cin.eof()) exit(0);
            print("nick_name : ");
            std::cin >> this->phoneBook[emptyArrayNum].nickName;
            if (std::cin.eof()) exit(0);
            print("phone_number : ");
            std::cin >> this->phoneBook[emptyArrayNum].phoneNumber;
            if (std::cin.eof()) exit(0);
            print("secreat_memo : ");
            std::cin >> this->phoneBook[emptyArrayNum].secreatMemo;
            if (std::cin.eof()) exit(0);
            if (cnt < 8)
                cnt++;
            this->phoneBook[emptyArrayNum].num = this->cnt;
        }

        void printPhoneBook(int idx) {
            std::cout << std::setw(10); 
            print(phoneBook[idx].num);
            print("|");
            print(phoneBook[idx].name);
            print("|");
            print(phoneBook[idx].firstName);
            print("|");
            print(phoneBook[idx].phoneNumber);
            print("|");
            return ;       
        }

        void searchPhoneBook() {
            if (this->cnt == 0) {
                printEndl("empty phoneBook");
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
                for (int i = 0; i < 8; i++) {
                    if (this->phoneBook[i].num == searchNumber) printPhoneBook(i);
                }
            }
        }

        void exitPhoneBook() {
            printEndl("EXIT");
            exit(0);
        }

    public:
        void _setCmdInit() { 
            std::memset(phoneBook, 0, sizeof(t_phoneBook) * 8); 
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
