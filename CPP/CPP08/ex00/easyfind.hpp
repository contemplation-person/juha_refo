#pragma once
#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
    return std::find(container.begin(), container.end(), n);
}

#endif 
