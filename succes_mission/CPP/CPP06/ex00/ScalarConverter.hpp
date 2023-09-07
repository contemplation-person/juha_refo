#pragma once
#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__

#include <iostream>
#include <exception>

class ScalarConverter
{
public :

	static void convert(const char* str); // char, int, float, double


private :
    static void printChar(const double d) ;
    static void printInt(const double d) ;
    static void printfloat(const double d) ;
    static void printDouble(const double d) ;

	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
};
#endif


