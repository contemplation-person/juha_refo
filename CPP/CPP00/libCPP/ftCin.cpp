#include "LibCPP.hpp"
#include <cstdio>

int isCinErr(std::string errorMessage) {
    if (!std::cin.good()) {
        std::cin.clear();
        std::clearerr(stdin);
        printEndl(errorMessage);
        return (true);
    }
    return (false);
}
