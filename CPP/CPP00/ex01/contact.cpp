#include "Contact.hpp"

Contact::Contact() : _num(0), _name(""), _firstName(""), _phoneNumber(""), _secretMemo(""), _nickName("") {};

// 10자가 넘어가면 9자 출력 10번째자 .으로 대체 
void        Contact::setNum(int num) { _num = num; }
void        Contact::setName(std::string name) { _name = name; }
void        Contact::setNickName(std::string nickName) { _nickName = nickName; }
void        Contact::setFirstName(std::string firstName) { _firstName = firstName; }
void        Contact::setPhoneNumber(std::string phoneNumber) { _phoneNumber = phoneNumber; }
void        Contact::setSecretMemo(std::string secretMemo) { _secretMemo = secretMemo; }

int         Contact::getNum() { return (_num);}
std::string Contact::getName() { return (_name);}
std::string Contact::getFirstName() { return (_firstName);}
std::string Contact::getPhoneNumber() { return (_phoneNumber);}
std::string Contact::getSecretMemo() { return (_secretMemo);} 
std::string Contact::getNickName() { return (_nickName);}

