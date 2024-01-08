#pragma once
#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <cstdint>
#include <string>
#include <iostream>

typedef struct S_Data
{
    std::string str;
}Data;

class Serializer
{
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer& s);
    const Serializer operator=(const Serializer& s);
};

#endif
