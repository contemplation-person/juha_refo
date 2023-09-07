#ifndef __SPAN_HPP__
#define __SPAN_HPP__
#include <vector>

class Span
{
public :
	Span(unsigned int capacity);
	~Span();
	Span(const Span& span);
	Span &operator=(const Span& span);

	int		shortestSpan();
	int		longestSpan();
	void	addNumber(int num);
	void	addNumber(int num, int num2);

private :
	Span();

	std::vector<int>	_numbers;
};

#endif
