#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <string>
#include <limits>

ScalarConverter::ScalarConverter() { }
ScalarConverter::~ScalarConverter() { }

void ScalarConverter::printChar(const double d) 
{
    char c;

    c = static_cast<char>(d);
    std::cout << "char\t: ";
    if (0 > d || 255 < d)
        std::cout << "impossible" << std::endl;
    else if (32 > d || 128 < d)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "\'" << static_cast<char>(d) << "\'" << std::endl;
}

void ScalarConverter::printInt(const double d) 
{
    int i = static_cast<int>(d);
    if ((d > 0 && i <= 0)
        ||(d < 0 && i <= 0))
        std::cout << "int\t: impossible" << std::endl;
    else
        std::cout << "int\t: " << i << std::endl;
}

#include <iomanip>
void ScalarConverter::printfloat(const double d) 
{
    // 출력길이 인쇄
    float f =  static_cast<float>(d);
    std::cout << "float\t: " << std::setprecision(std::numeric_limits<float>::digits10) << f << 'f' << std::endl;
}

void ScalarConverter::printDouble(const double d) 
{
    std::cout << "double\t: " << std::setprecision(std::numeric_limits<double>::digits10) << d << std::endl;
}

void ScalarConverter::convert(const char* str)
{
    char    *p_end;
    bool    isNan = false;
	double  d;
    const char    *point = std::strchr(str, '.');

    d = std::strtod(str,  &p_end);
/*
    std::cout << "origin str\t: " << str << std::endl
              << "double\t\t: " << d << std::endl
              << "p_end\t\t: " << *p_end << std::endl << std::endl;

*/
    if (point && std::strlen(point) == 2 && point[1] == 'f')
        isNan = true;
    if (d == 0 
        && std::strlen(str) == 1 
        && std::strlen(p_end) == 1
        ) 
    {
        printChar(*p_end);
        printInt(*p_end);
        printfloat(*p_end);
        printDouble(*p_end);
    } 
    else if ((std::strlen(p_end) == 0 || (*p_end == 'f' && std::strlen(p_end) == 1)) && !isNan)
    {
        printChar(d);
        printInt(d);
        printfloat(d);
        printDouble(d);
    } 
    else 
    {
        std::cout << "char\t: impossible" << std::endl
                  << "int\t: impossible" << std::endl
                  << "float\t: nanf" << std::endl
                  << "double\t: nan" << std::endl;
    }
}

