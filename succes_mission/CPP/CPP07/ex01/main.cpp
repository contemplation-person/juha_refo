#include "iter.hpp"

int main( void ) {
    int intArr[3] ={1, 2, 3};
    double doubleArr[3] ={1.1, 2.1, 3.1};
    char charArr[3] ={'a', 'b', 'c'};
    int arrLen = 3;

    std::cout << "===int===" << std::endl;
    iter(intArr, arrLen, callArr);
    std::cout << "===double===" << std::endl;
    iter(doubleArr, arrLen, callArr);
    std::cout << "===char===" << std::endl;
    iter(charArr, arrLen, callArr);
}
