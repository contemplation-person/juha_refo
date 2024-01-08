#pragma once

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
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
