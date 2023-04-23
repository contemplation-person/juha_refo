#include "ScalarConverter.hpp"
#include <cstdlib>

ScalarConverter::ScalarConverter() { }
ScalarConverter::~ScalarConverter() { }

void ScalarConverter::convert(const char * str)
{
	long	l;
	int		i;
	char	c;
	float	f;
	double	d;

	try 
	{
		l = atol(str);
	} catch (std::exception &e) {
		e.what();
		return ;
	}
	try
	{
		i = static_cast<int>(l);
		std::cout << "char: ";
		if (i != l)
			throw ImpossibleException();
	} catch (std::exception &e) {
		std::cout << "impossible" << std::endl;

	}
	c = static_cast<char>(i);
	f = 
	d = static_cast<double>(i);
	std::cout << "char: ";
	if (static_cast<int>(i) != l || c < 32 || c > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'"  << c << "\'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

const char* ScalarConverter::ImpossibleException::what() const throw()
{
	return "impossible";
}