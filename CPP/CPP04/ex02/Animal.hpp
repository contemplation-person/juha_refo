#pragma once

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
private:
protected:
    std::string type;
public:
    Animal();
    virtual ~Animal();
    Animal(const Animal& animal);
    Animal& operator=(const Animal& animal);
    virtual void  makeSound() const = 0;
};

#endif
