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

	static void convert(const char* str); // char, int, float, double

private :
    static void printChar(const int d) ;
    static void printInt(const double d) ;
    static void printfloat(const double d) ;
    static void printDouble(const double d) ;

	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
};
#endif


