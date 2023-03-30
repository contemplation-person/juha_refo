#pragma once
#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <iostream>

class Brain
{
private:
    std::string ideas[100];

public:
    Brain();
    ~Brain();
    Brain& operator=(const Brain& brain);
    Brain(const Brain& brain);
};

#endif

