#pragma once

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
private:
protected:
    std::string type;
public:

    WrongAnimal();
    virtual ~WrongAnimal();
    WrongAnimal(const WrongAnimal& animal);
    WrongAnimal& operator=(const WrongAnimal& animal);
    void setType(std::string type);
    std::string getType() const;
    void makeSound() const;
};

#endif
