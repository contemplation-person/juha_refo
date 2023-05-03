#include "ScalarConverter.hpp"
#include <cstdlib>
#include <string>
#include <limits>

ScalarConverter::ScalarConverter() { }
ScalarConverter::~ScalarConverter() { }

void ScalarConverter::printChar(const int d) 
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
    if (d > INT_MAX || d < INT_MIN)
    {
        printChar(4242);
        std::cout << "int\t: impossible" << std::endl;
    } else {
        int i = static_cast<char>(d);
        printChar(i);
        i = static_cast<int>(d);
        std::cout <<"int\t: " << i << std::endl;
    }
}

#include <iomanip>
void ScalarConverter::printfloat(const double d) 
{
    // 출력길이 인쇄
    std::cout << "float\t: " << std::fixed << std::setprecision(2) << static_cast<float>(d) << 'f' << std::endl;
}

void ScalarConverter::printDouble(const double d) 
{
    // 출력길이 인쇄
    std::cout<< "double\t: "<< d << std::endl;
}

#include <string>
void ScalarConverter::convert(const char* str)
{
	double	d;
    char    *p_end;
    bool    isNan = false;

    
    d = std::strtold(str, &p_end);
/*
    std::cout << "origin str\t: " << str << std::endl
              << "double\t: " << d << std::endl
              << "p_end\t: " << *p_end << std::endl;
*/
    if (str && strlen(str) == 1)
    {
        printInt(*str);  
        printfloat(*str);
        printDouble(*str);
        return ;
    } else if (*str == '.' 
        || (*p_end != 'f' && *p_end != '\0') 
        || strlen(p_end) > 1)
    {
        isNan = true;
    }
    if (isNan)
    {
        std::cout << "char\t: impossible" << std::endl
                  << "int\t: impossible" << std::endl
                  << "float\t: nanf" << std::endl
                  << "double\t: nan" << std::endl;
    } else {
        printInt(d);
        printfloat(d);
        printDouble(d);
    }
}


