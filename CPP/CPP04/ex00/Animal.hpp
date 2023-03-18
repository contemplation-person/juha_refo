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
    ~Animal();
    Animal(const Animal& animal);
    Animal& operator=(const Animal& animal);
    void setType(std::string type);
    std::string getType() const;
    virtual void makeSound() const;
};

#endif
