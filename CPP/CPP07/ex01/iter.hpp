#pragma once
#ifndef __iter__
#define __iter__

#include <iostream>

template<class T>
void callArr(T* arr, int arrLen)
{
    for (int i = 0; i < arrLen; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

template<class T>
void iter(T *arr, int arrLen, void (*callArr)(T*,int))
{
    callArr(arr, arrLen);
};

#endif
