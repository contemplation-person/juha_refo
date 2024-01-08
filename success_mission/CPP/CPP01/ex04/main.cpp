#include "Sed.hpp"

#include <iostream>
int main(int c, char **v)
{
    if (c != 4)
        return (1);
    Sed s(v[1], v[2], v[3]);
    s.replace();
    return (0);
}
