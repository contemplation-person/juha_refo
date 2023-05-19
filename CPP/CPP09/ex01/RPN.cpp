#include "RPN.hpp"
#include <stack>
#include <iostream>
#include <sstream>
#include <string>
#include <climits>

const char* RPN::OutofRange::what() const throw() {
	return " : RPNOutOfRange";
}

const char* RPN::BadInput::what() const throw() {
	return " : Bad input";
}

const char* RPN::DividZero::what() const throw() {
    return " : DividZero";
}

RPN::RPN(const char *input)
	: _str(input)
{
	std::string		    str(input);
	std::stack<int>		numbers;
	std::stringstream	sstream;

	if (str.find_first_not_of("0123456789+-*/ ")
		!= std::string::npos)
	{
		std::cout << _str;
		throw RPN::BadInput();
	}
	str.erase(str.find_last_not_of(" ") + 1);

	int			integer;
	std::string sOperator;

	while (!str.empty())
	{
		str.erase(0, str.find_first_not_of(" "));
		if (str.empty())
			break; 
		if (std::isdigit(*str.begin()))
		{
			sstream << str.substr(0, 2);
			sstream >> integer;
            if (integer > 10 || integer < -10)
            {
                std::cout << _str;
                throw RPN::OutofRange();
            }
			numbers.push(integer);
			str.erase(0, str.find_first_not_of("0123456789"));
			if (!str.empty() && str[0] != ' ')
			{
				std::cout << _str;
				throw RPN::BadInput();
			} 
			sstream.clear();
		}
		else
		{
			if (numbers.size() < 2)
			{
				std::cout << _str;
				throw RPN::BadInput();
			}
			long long result = 0;
			switch (*str.begin())
			{
			case '+':
				result = numbers.top();
				numbers.pop();
				result = numbers.top() + result;
				numbers.pop();
				numbers.push(static_cast<int>(result));
				break;
			case '-':
				result = numbers.top();
				numbers.pop();
				result = numbers.top() - result;
				numbers.pop();
				numbers.push(static_cast<int>(result));
				break;
			case '*':
				result = numbers.top();
				numbers.pop();
				result = numbers.top() * result;
				numbers.pop();
				numbers.push(static_cast<int>(result));
				break;
			default:
				result = numbers.top();
				numbers.pop();
                if (result == 0)
                {
                    std::cout << _str;
                    throw RPN::DividZero();
                }
				result = numbers.top() / result;
				numbers.pop();
				numbers.push(static_cast<int>(result));
				break;
			}
			if (result > INT_MAX || result < INT_MIN)
			{
				std::cout << _str;
				throw RPN::OutofRange();
			}
			str.erase(0, str.find_first_not_of("+-*/"));
			if (!str.empty() && str[0] != ' ')
			{
				std::cout << _str;
				throw RPN::BadInput();
			}
		}
	}
	if (numbers.size() != 1)
	{
		std::cout << _str;
		throw RPN::BadInput();
	}
	std::cout << numbers.top() << std::endl;
}

RPN::~RPN() {}