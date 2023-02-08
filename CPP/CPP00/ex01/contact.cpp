#include "Contact.hpp"
#include <iomanip>

// 10자가 넘어가면 9자 출력 10번째자 .으로 대체 
void  Contact::setNum(int num) { _num = num; }
void  Contact::setName(std::string name) { 
    if (name.size() > 10) {
        name.erase(10);
        name[9] = '.';
    }
    _name = name; 
}

void  Contact::setFirstName(std::string firstName) {
    if (firstName.size() > 10) {
        firstName.erase(10);
        firstName[9] = '.';
    }
    _firstName = firstName; 
}

void  Contact::setPhoneNumber(std::string phoneNumber) {
    if (phoneNumber.size() > 10) {
        phoneNumber.erase(10);
        phoneNumber[9] = '.';
    }
    _phoneNumber = phoneNumber; 
}

void  Contact::setSecreatMemo(std::string secreatMemo) {
    if (secreatMemo.size() > 10) {
        secreatMemo.erase(10);
        secreatMemo[9] = '.';
    }
    _secreatMemo = secreatMemo; 
}

int         Contact::getNum() { return (_num);}
std::string Contact::getName() { return (_name);}
std::string Contact::getFirstName() { return (_firstName);}
std::string Contact::getPhoneNumber() { return (_phoneNumber);}
std::string Contact::getSecreatMemo() { return (_secreatMemo);} 

void Contact::printAllContact() {
    std::cout << std::setw(10); 
    print(getNum());
    print("|");
    std::cout << std::setw(10); 
    print(getName());
    print("|");
    std::cout << std::setw(10); 
    print(getFirstName());
    print("|");
    std::cout << std::setw(10); 
    print(getPhoneNumber());
    print("|");
}
