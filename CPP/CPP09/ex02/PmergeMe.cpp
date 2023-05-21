#include "PmergeMe.hpp"
#include <iostream>

std::string makeString(int argc, char **argv)
{
	std::string s;

    for (int i = 1; i < argc; i++)
    {
        s += argv[i];
        if (i != argc - 1)
            s += " ";
    }
	return s;
}

void printResult(std::string const& s, std::vector<int> const& v
				, std::list<int>& l)
{
	(void) l;

	std::cout << "Before: " << s << std::endl;
	std::cout << "After: ";
	for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of \t " << v.size() << " elements with std::vector : " << std::endl;
	//vector time
	std::cout << "Time to process a range of \t " << v.size() << " elements with std::list   : " << std::endl;
	//list time


}