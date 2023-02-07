#pragma once
#include "../libcpp/LibCPP.hpp"

class Contact {
private:
    int         _num = 0;
    std::string _name = "";
    std::string _firstName = "";
    std::string _phoneNumber = "";
    std::string _secreatMemo = "";

public:
    void        setNum(int num);
    void        setName(std::string name);
    void        setFirstName(std::string firstName);
    void        setPhoneNumber(std::string phoneNumber);
    void        setSecreatMemo(std::string secreatMemo);

    int         getNum();
    std::string getName();
    std::string getFirstName();
    std::string getPhoneBook();
    std::string getSecreatMemo();
};
