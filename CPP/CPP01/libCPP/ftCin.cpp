#include "LibCPP.hpp"

int isCinErr() {
    if (!std::cin.good()) {
        std::cin.clear();
        std::clearerr(stdin);
        printEndl("EOF or Error");
        return (true);
    }
    return (false);
}
