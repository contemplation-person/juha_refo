#include "Harl.hpp"

int main(int c, char **v) {
    if (c != 2) return (0);

    Harl Harl;
    Harl.complain(v[1]);
    return (0);
}
