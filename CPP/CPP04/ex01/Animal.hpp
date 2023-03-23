#pragma once

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {
private:
protected:
    std::string type;
public:
    Animal();
    virtual ~Animal();
    Animal(const Animal& animal);
    Animal& operator=(const Animal& animal);

    void          setType(std::string type);
    virtual void  makeSound() const;
    std::string   getType() const; 

    virtual void printBrain() = 0;
};

#endif
