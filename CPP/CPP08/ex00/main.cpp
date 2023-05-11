#include "easyfind.hpp"

#include <stdexcept>
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main(void) 
{
    std::vector<int> v;
    std::list<int> l;
    std::deque<int> d;
    for (int i = 0; i < 4; i++)
    {
        d.push_back(i);
        l.push_back(i);
    }

    easyfind(v, 1);
    std::cout << *easyfind(l, 1) << std::endl;
    std::cout << *easyfind<std::deque<int> >(d, 2) << std::endl;
    
    return 0;
}
