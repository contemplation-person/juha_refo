#pragma once
#ifndef __MY_EXCEPTION__
#define __MY_EXCEPTION__

#include <iostream>

class MyException {
public:  
    MyException();
    MyException(int line, std::string file, std::string massage);
    virtual void print();

protected:
    int         _line;
    std::string _file;
    std::string _massage;
private:
};

class GradeTooHighException : public MyException{
public:
    GradeTooHighException();
    GradeTooHighException(int line, std::string file, std::string _name, int _grade);
};

class GradeTooLowException : public MyException{
public:
    GradeTooLowException();
    GradeTooLowException(int line, std::string file, std::string _name, int _grade);
};
#endif
