#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) 
{
    if (argc != 2)
    {
        std::cout << "제발 제대로 된 인풋을 넣어주세요." << std::endl;
        return 0;
    }
    try
    {
        RPN(*(argv + 1));
    } 
    catch(const std::exception& e) 
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
