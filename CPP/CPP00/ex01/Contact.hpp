#pragma once
#include "../libCPP/LibCPP.hpp"

class Contact {
private:
    int         _num;
    std::string _name;
    std::string _firstName;
    std::string _phoneNumber;
    std::string _secreatMemo;

public:
    Contact() {
        _num = 0;
        _name = "";
        _firstName = "";
        _phoneNumber = "";
        _secreatMemo = "";
    }

    void        setNum(int num);
    void        setName(std::string name);
    void        setFirstName(std::string firstName);
    void        setPhoneNumber(std::string phoneNumber);
    void        setSecreatMemo(std::string secreatMemo);

    int         getNum();
    std::string getName();
    std::string getFirstName();
    std::string getPhoneNumber();
    std::string getSecreatMemo();

    void        printAllContact();
};
