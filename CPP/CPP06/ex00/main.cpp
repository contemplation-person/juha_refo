#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) return 0;
    ScalarConverter s;
    s.convert(argv[1]);
    return 0;
}
