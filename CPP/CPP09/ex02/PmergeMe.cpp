#include "PmergeMe.hpp"
#include <iostream>

std::string makeString(int argc, char **argv)
{
	std::string str;

    for (int i = 1; i < argc; i++)
    {
        str+= argv[i];
        if (i != argc - 1)
            str+= " ";
    }
	return str;
}

void printResult(std::string const& input, std::vector<int> const& vector
				, std::list<int>& list)
{
	(void) list;

	std::cout << "Before: " << input << std::endl;
	std::cout << "After: ";
	for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of \t " << vector.size() << " elements with std::vector : " << std::endl;
	//vector time
	std::cout << "Time to process a range of \t " << vector.size() << " elements with std::list   : " << std::endl;
	//list time


}
