#pragma once
#ifndef __iter__
#define __iter__

#include <iostream>

template<typename T>
void iter(T* arr, int arrLen, void(*f)(const T &))
{
    for (int i = 0; i < arrLen; i++)
        f(arr[i]);
};

#endif
