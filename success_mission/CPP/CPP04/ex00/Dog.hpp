#pragma once

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal {
private:
public:
    Dog();
    virtual ~Dog();
    Dog(const Dog& dog);
    Dog& operator=(const Dog& dog);
    virtual void makeSound() const;
};

#endif
