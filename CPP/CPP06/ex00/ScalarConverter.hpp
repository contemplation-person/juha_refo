#pragma once
#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__

#include <iostream>
#include <exception>

class ScalarConverter
{
public :
	ScalarConverter();
	~ScalarConverter();

	void convert(const char* str); // char, int, float, double

private :
    void printChar(const int d) const;
    void printInt(const double d) const;
    void printfloat(const double d) const;
    void printDouble(const double d) const;

	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
};
#endif


