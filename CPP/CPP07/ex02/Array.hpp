#pragma once
#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

template<class T> 
class Array
{
public:
    Array();
    ~Array();
    Array(const Array& arr);
    const Array& operator=(const Array& arr);

private:
    int size = 0;
};

#endif
