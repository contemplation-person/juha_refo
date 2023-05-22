#ifndef __PmergeMe_hpp__
#define __PmergeMe_hpp__
#define RUN 32

#include <string>
#include <climits>
#include <vector>
#include <list>
#include <sstream>
#include <exception>

std::string makeString(int argc, char **argv);
void printResult(std::string const& input, std::vector<int> const& vector
				, std::list<int> const& list);

/*------------------------template-------------------------------*/

template <typename T>
void sort(T& container)
{
	int minRun = container.size() / RUN;
    int remain = container.size() % RUN;

    for (int i = 0; i < RUN; i++)

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
