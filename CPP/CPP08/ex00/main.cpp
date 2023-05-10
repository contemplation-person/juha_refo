#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void) 
{
    std::vector<int> v;
    std::list<int> l = {1, 2, 3, 4};
    std::deque<int> d = {1, 2, 3, 4};
    easyfind(v, 1);
    std::cout << *easyfind(l, 1) << std::endl;
    std::cout << *easyfind(d, 2) << std::endl;
    return 0;
}