#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) return 0;
    ScalarConverter::convert(argv[1]);
    std::cout << "리터럴" << std::endl;
    ScalarConverter::convert(1);
    return 0;
}
