#pragma once

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal {
private:
public:
    WrongCat();
    virtual ~WrongCat();
    WrongCat(const WrongCat& cat);
    WrongCat& operator=(const WrongCat& cat);
    virtual void makeSound() const;
};

#endif
