#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv) 
{
   BitcoinExchange exchange;
    if (argc != 2)
       std::cout << "\033[31m인자 갯수가 맞지 않습니다.\033[0m" << std::endl;
    std::FILE* fp = fopen(argv[1], "r");
    if (!fp)
       std::cout << "\033[31mError: could not open file.\033[0m" << std::endl;
}
