#pragma once

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal {
private:
protected:
    std::string type;
public:
    AAnimal();
    virtual ~AAnimal();
    AAnimal(const AAnimal& AAnimal);
    AAnimal& operator=(const AAnimal& AAnimal);

    virtual void  makeSound() const = 0;
};

#endif
