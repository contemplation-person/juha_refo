#ifndef __PmergeMe_hpp__
#define __PmergeMe_hpp__
#define RUN 32

#include <string>
#include <climits>
#include <cstddef>
#include <vector>
#include <deque>
#include <sstream>
#include <exception>
#include <iostream>

std::string makeString(int argc, char **argv);
void printResult(std::string const& input, std::vector<int> const& vector
				, std::deque<int> const& list);

/*------------------------template-------------------------------*/

template <typename T>
void insertSort(T& container, std::size_t start, std::size_t end)
{
    std::size_t location;
    std::size_t swapIdx;

    for(std::size_t i = start; i < end; i++)
    {
        if (i == 0)
            continue;
        location = i;
        swapIdx = i - 1;
        while (location != start)
        {
            if (container[location] < container[swapIdx])
                std::swap(container[location], container[swapIdx]);
            else
                break;
            location = swapIdx;
            swapIdx--;
        }
    }
}

template <typename T>
void mergeSort(T& container, int location, int size)
{
	std::size_t minRun = container.size() / RUN;

	tmp = container.begin() + location;

	std::cout << "test : ";
	for (std::size_t i = 0; i < container.size(); i++)
		std::cout << container[i] << " ";
}

template <typename T>
void sort(T& container)
{
	std::size_t minRun = container.size() / RUN; // RUN  == 32

    if (minRun == 0)
    {
        insertSort(container, 0, container.size());
        return ;
    }
    for (std::size_t i = 0; i < minRun; i++)
    {
        if (minRun - 1 == i)
        {
            insertSort(container, i * RUN, container.size());
            break ;
        }
        insertSort(container, i * RUN, (i + 1) * RUN);
    }
    void mergeSort(T& container, int location, int size);
}

template <typename T>
void parse(std::string const& input, T& container)
{
	if (input.empty())
		throw std::invalid_argument("empty string");
	if (input.find_first_not_of("0123456789 ") != std::string::npos)
		throw std::invalid_argument("Bad input");

	std::stringstream sstream(input);

	long long l;

	while (sstream >> l)
	{
		if (l > INT_MAX || l < INT_MIN)
		{
			throw std::out_of_range("Out of range");
		}
		container.push_back(static_cast<int>(l));
		if (sstream.peek() == ' ')
			sstream.ignore();
	}
}

#endif
