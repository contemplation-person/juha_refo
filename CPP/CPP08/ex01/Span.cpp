#include "Span.hpp"


Span::Span(unsigned int capacity)
{
	_numbers.reserve(capacity);
}

Span::~Span() 
{ }

Span::Span(const Span& span)
{
	*this = span;
}

Span& Span::operator=(const Span& span)
{
	if (this != &span)
	{
		_numbers = span._numbers;
	}
	return *this;
}

void Span::addNumber(int num)
{
    _numbers.push_back(num);
}

#include <algorithm>
int Span::shortestSpan()
{
	if (_numbers.size() < 2)
	{
		throw "Span is too short";
	}
	else
	{
		std::vector<int> tmp = _numbers;
		std::sort(tmp.begin(), tmp.end());
		std::vector<int>::iterator it = tmp.begin();
		int min = *(it + 1) - *it;
		for (; it != tmp.end() - 1; it++)
		{
			if (*(it + 1) - *it < min)
				min = *(it + 1) - *it;
		}
		return min;
	}
}

int Span::longestSpan()
{
	if (_numbers.size() < 2)
	{
		throw "Span is too short";
	}
	else
	{
		std::vector<int> tmp = _numbers;
		std::sort(tmp.begin(), tmp.end());
		return *(tmp.end() - 1) - *tmp.begin();
	}
}
