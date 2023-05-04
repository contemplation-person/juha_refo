#pragma once
#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <climits>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <cstring>

template<class T> 
class Array
{
public:
    Array();
    Array(std::size_t ui); //
    virtual ~Array();
    Array(const Array& arr);
    const Array<T>& operator=(T t);
    Array& operator=(const Array& arr) ;
    void* operator new[](const std::size_t ui);
    T& operator[](const std::size_t ui);
    
    std::size_t size();

private:
    T*  _arr;
    std::size_t _size;
};

template<class T>
Array<T>::Array(void)
    : _size(0)
{
    this->_arr = new T[0];
}

template<class T>
Array<T>::~Array(void) 
{
    delete [] _arr;
}

template<class T>
Array<T>::Array(const std::size_t ui) 
    : _size(ui)
{
    this->_arr = new T[ui];// malloc vs new
}

template<class T>
Array<T>::Array(const Array& arr) 
    : _size(arr._size)
{
    this->_arr = new T[arr._size];
    for(std::size_t i = 0; i < arr._size; i++)
    {
        this->_arr[i] = arr._arr[i];
    }
    this->_size = arr._size;
}

template<class T>
Array<T>& Array<T>::operator=(const Array& arr) 
{
    if (this != &arr)
    {
        this->_arr = new T[arr._size];
        for(std::size_t i = 0; i < arr._size; i++)
        {
            this->_arr[i] = arr._arr[i];
        }
        this->_size = arr._size;
    }
    return *this; 
}

template<class T>
T& Array<T>::operator[](const std::size_t ui)
{
    if (_size <= ui)
        throw std::out_of_range("out of range");
    return this->_arr[ui];
}

template<class T>
std::size_t Array<T>::size()
{
    return this->_size;
}

#endif
