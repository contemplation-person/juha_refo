#include "Contact.hpp"

void  Contact::setNum(int num) { _num= num; }
void  Contact::setName(std::string name) { _name = name; }
void  Contact::setFirstName(std::string firstName) { _firstName = firstName; }
void  Contact::setPhoneNumber(std::string phoneNumber) { _phoneNumber = phoneNumber; }
void  Contact::setSecreatMemo(std::string secreatMemo) { _secreatMemo = secreatMemo; }

int         Contact::getNum() { return (_num);}
std::string Contact::getName() { return (_name);}
std::string Contact::getFirstName() { return (_firstName);}
std::string Contact::getPhoneBook() { return (_phoneNumber);}
std::string Contact::getSecreatMemo() { return (_secreatMemo);} 

