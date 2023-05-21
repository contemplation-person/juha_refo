#ifndef __PmergeMe_hpp__
#define __PmergeMe_hpp__
#include <string>
#include <climits>
#include <vector>
#include <list>
#include <sstream>
#include <exception>

std::string makeString(int argc, char **argv);
void printResult(std::string const& s, std::vector<int> const& v
				, std::list<int> const& l);

/*------------------------template-------------------------------*/

template <typename T>
void sort(T& container)
{
	int minRun = container.size() / 32;

	divide(container, minRun);
}

template <typename T>
void parse(std::string const& s, T& t)
{
	if (s.empty())
		throw std::invalid_argument("empty string");
	if (s.find_first_not_of("0123456789 ") != std::string::npos)
		throw std::invalid_argument("Bad input");

	std::stringstream sstream(s);

	long long l;

	while (sstream >> l)
	{
		if (l > INT_MAX || l < INT_MIN)
		{
			throw std::out_of_range("Out of range");
		}
		t.push_back(static_cast<int>(l));
		if (sstream.peek() == ' ')
			sstream.ignore();
	}
}

#endif