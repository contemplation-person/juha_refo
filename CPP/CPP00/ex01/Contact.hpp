#pragma once
#include "../libCPP/LibCPP.hpp"

class Contact {
private:
    int         _num;
    std::string _name;
    std::string _firstName;
    std::string _phoneNumber;
    std::string _secretMemo;
    std::string _nickName;

public:
    Contact();
    void        setNum(int num);
    void        setName(std::string name);
    void        setNickName(std::string name);
    void        setFirstName(std::string firstName);
    void        setPhoneNumber(std::string phoneNumber);
    void        setSecretMemo(std::string secretMemo);

    int         getNum();
    std::string getName();
    std::string getFirstName();
    std::string getPhoneNumber();
    std::string getSecretMemo();
    std::string getNickName();
};
