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
void forwardMerge(T& container, std::size_t& start, std::size_t& part1, std::size_t& part2)
{
    T tmp;

    for (int i = start; i < part1; i++)
        tmp.push_back(container[i]);
    
    std::size_t part1idx = 0;
    std::size_t part2idx = part1;
    std::size_t containerIdx = start;
    bool isTmp = true;

    while (part2idx != part2 && (isTmp || part1idx != part2idx))
    {
        if (isTmp)
        {
            if (tmp[part1idx] < container[part2idx])
            {
                container[containerIdx] = tmp[part1idx];
                part1idx++;
                if (part1idx == tmp.size())
                {
                    isTmp = false;
                    part1idx = start;
                }
                containerIdx++;
            }
            else
            {
                container[containerIdx] = container[part2idx];
                part2idx++;
                containerIdx++;
            }
        }
        else
        {
            if (container[part1idx] < container[part2idx])
            {
                container[containerIdx] = container[part1idx];
                part1idx++;
                containerIdx++;
            }
            else
            {
                container[containerIdx] = container[part2idx];
                part2idx++;
                containerIdx++;
            }
        }
    }
}

template <typename T>
void reversMerge(T& container, std::size_t& start, std::size_t& part1, std::size_t& part2)
{
    T tmp;

    for (int i = part1; i < part2; i++)
        tmp.push_back(container[i]);
    
    std::size_t part1idx = part1 - 1;
    std::size_t part2idx = tmp.size() - 1;
    std::size_t containerIdx = part2 - 1;
    bool isTmp = true;

    while (part1idx != start && (isTmp || part2idx != part1idx))
    {
        if (isTmp)
        {
            if (tmp[part2idx] > container[part1idx])
            {
                container[containerIdx] = tmp[part2idx];
                if (part2idx != 0)
                    part2idx--;
                else
                {
                    isTmp = false;
                    part2idx = part1 - 1;
                }
                containerIdx--;
            }
            else
            {
                container[containerIdx] = container[part1idx];
                part1idx--;
                containerIdx--;
            }
        }
        else
        {
            if (container[part2idx] > container[part1idx])
            {
                container[containerIdx] = container[part2idx];
                part2idx--;
                containerIdx--;
            }
            else
            {
                container[containerIdx] = container[part1idx];
                part1idx--;
                containerIdx--;
            }
        }
    }

}
template <typename T>
void mergeSort(T& container, std::size_t start, std::size_t part1, std::size_t part2)
{
    bool isPart2 = part1 - start < part2 - part1;
    std::size_t size = isPart2 ? part2 - part1 : part1 - start;
    
    if (isPart2)
        forwardMerge(container, start, part1, part2, size);
    else
        reversMerge(container, start, part1, part2, size);

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
            if (minRun == 1)
                return ;
            break ;
        }
        insertSort(container, i * RUN, (i + 1) * RUN);
    }

// WIP mergesort implimentation
	bool isRemain = (container.size() % RUN) != 0;
    std::size_t remainIdx = 0;

    while (!isRemain && minRun != 0)
    {
        if (isRemain)
        {
            remainIdx = container.size() / miniRun;
        }
        minRun /= 2;
        for (std::size_t i = 0; i < minRun; i++)
        {
            
        }

    }
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
