#ifndef __PmergeMe_hpp__
#define __PmergeMe_hpp__
#define RUN 32

#include <string>
#include <climits>
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
void insertSort(T& container, int minRun, int remain, int count)
{
	if (count > 1)
	{
		//로직 문제 있음. 자고 생각하기
		for (int i = count * RUN; i < (count + 1) * RUN; i++)
		{
			for (int j = i; count * RUN < j; j--)
			{
				if (container[j] < container[j - 1])
					std::swap(container[j], container[j - 1]);
				else
					break ;
			}
		}
		insertSort(container, minRun, remain, count - 1);
	}
	else if (count == 1)
	{
		for (std::size_t i = (minRun - 1) * RUN; i < container.size(); i++)
		{
			for (int j = i; (minRun - 1) * RUN < j; j--)
			{
				if (container[j] < container[j - 1])
					std::swap(container[j], container[j - 1]);
				else
					break ;
			}
		}
		return ;
	}
	else if (minRun < 1)
	{
		for (std::size_t i = 0; i < container.size(); i++)
		{
			for (int j = i; 0 < j; j--)
			{
				if (container[j] < container[j - 1])
					std::swap(container[j], container[j - 1]);
				else
					break ;
			}
		}
		return ;
	}
}

/*
template <typename T>
void mergeSort(T& container, int location, int size)
{
	T tmp.reserve(size);

	tmp = container.begin() + location;

}
*/

template <typename T>
void sort(T& container)
{
	int minRun = container.size() / RUN;
	int remain = container.size() % RUN;

	insertSort(container, minRun, remain, minRun);
	std::cout << "test : ";
	for (std::size_t i = 0; i < container.size(); i++)
		std::cout << container[i] << " ";
//	mergeSort(container, 0, RUN);
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
