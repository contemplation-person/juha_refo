#include "Serializer.hpp"


int main()
{
    Data d;
    d.str = "str";
    Data *dp = &d;

    std::cout << "dp\t: " << dp << std::endl;

    Serializer S;
    uintptr_t t = S.serialize(dp);
    std::cout << "uintptr_t\t: " << dp << std::endl;
    

    dp = S.deserialize(t);
    std::cout << "dp2\t: " << dp << std::endl;
    std::cout << "dp in\t: " << dp->str << std::endl;
    system("leaks Serializer");
}
