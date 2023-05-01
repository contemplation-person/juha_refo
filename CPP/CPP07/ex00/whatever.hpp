#pragma once
#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

template<class T>
void swap(T& a, T& b)
{
    T you_must_reference;

    you_must_reference = a;
    a = b;
    b = you_must_reference;
};

template<class T>
T min(T compare_a, T compare_b)
{
    if (compare_a < compare_b) return compare_a;
    return compare_b;
};

template<class T>
T max(T compare_a, T compare_b)
{
    if (compare_a > compare_b) return compare_a;
    return compare_b;
};

#endif
