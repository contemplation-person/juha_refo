#pragma once
#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include "iostream"

class Brain
{
private:
    std::string ideas[100];
    Brain(const Brain& brain);
    Brain& operator=(const Brain& brain);
public:
    Brain();
    ~Brain();
    void setIdeas(std::string str);
    void printIdeas();
};

#endif

