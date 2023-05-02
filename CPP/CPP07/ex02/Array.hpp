#pragma once
#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <cstdlib>

template<class T> 
class Array
{
public:
    Array();
    Array(unsigned int ui); //
    virtual ~Array();
    Array(const Array& arr);
    T operator=(T t);
    const Array& operator=(const Array& arr) const;
    void* operator new[](std::size_t ui);
    T operator[](std::size_t ui);
    
    int size();


private:
    T*  _arr;
    int _size;
};

template<class T>
Array<T>::Array(void)
    : _size(0)
{
    this->_arr = new T[0];
}

template<class T>
Array<T>::~Array(void) { }

#include <climits>
#include <stdexcept>
#include <iostream>

template<class T>
Array<T>::Array(unsigned int ui) 
    : _size(ui)
{
    try
    {
        if (static_cast<int>(ui) > INT_MAX)
            throw std::out_of_range("out of range");
        this->_arr = new T[ui];
        for (int i = 0; i < ui; i++)
        {
            _arr[i] = 0;
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

template<class T>
Array<T>::Array(const Array& arr) 
{
    this = arr;
}

template<class T>
T Array<class T> operator=(T t)
{

}

template<class T>
const Array<T>& Array<T>::operator=(const Array& arr) const 
{
    if (this != &arr)
    {
        this->_arr = new T[arr._size];
        for (int i = 0; i < arr._size;i++)
        {
            this->_arr[i] = arr[i];
        }
        this->_size = arr._size;
    }
    return *this; 
}
    
template<class T>
void* Array<T>::operator new[](std::size_t ui) // std::size_t를 써야 한다고 공식문서에 나와있음.
{
    Array tmp(ui);
    return tmp;
}

template<class T>
T Array<T>::operator[](std::size_t ui)
{
    try
    {
        if (static_cast<int>(ui) > INT_MAX)
            throw std::out_of_range("out of range");
        return this->_arr[ui];
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

template<class T>
int Array<T>::size()
{
    return this->_size;
}

#endif
