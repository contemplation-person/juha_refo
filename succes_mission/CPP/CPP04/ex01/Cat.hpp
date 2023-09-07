#pragma once

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain* brain;

public:
    Cat();
    virtual ~Cat();
    Cat(const Cat& cat);
    Cat& operator=(const Cat& cat);
    virtual void makeSound() const;
};

#endif
