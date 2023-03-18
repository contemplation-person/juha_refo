#pragma once

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <iostream>

class Cat : virtual public Animal {
private:
public:
    Cat();
    ~Cat();
    Cat(const Cat& cat);
    Cat& operator=(const Cat& cat);
    void makeSound();
};

#endif
