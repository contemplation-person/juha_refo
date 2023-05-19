#include "RPN.hpp"
#include <stack>
#include <iostream>
#include <climits>
#include <cctype>

bool isInstack(std::string& str, std::stack<int>& numbers)
{
	std::string tmp = "";
	int			integer = 0;

	str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
	str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);
	if (str.empty())
		return false;
	if (!std::isdigit(*str.begin()))
		return false;
	while ()// 와일 돌면서 숫자를 뽑고 그 숫자를 스택에 넣는다. 
	return true;
}

const char* RPN::RPNOutOfException::what() const throw() {
	return "RPNOutOfException";
}

RPN::RPN(std::string str)
{
	std::stack<int> numbers;
	long long		result = 0;

	while (!str.empty())
	{
		if (isInStack(str, numbers))
		{

		}
		if (result > INT_MAX || result < INT_MIN)
			throw RPNOutOfException();
	}
}

RPN::~RPN() {}