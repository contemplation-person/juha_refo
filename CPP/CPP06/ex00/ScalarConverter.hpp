#pragma once
#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__

#include <iostream>

class ScalarConverter
{
public :
	ScalarConverter();
	~ScalarConverter();

// char, int, float, double
	void convert(const char *str);

	class ImpossibleException : public std::exception
	{
	public :
		virtual const char *what() const throw();
	};

private :
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
};
#endif
