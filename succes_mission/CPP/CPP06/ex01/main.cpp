#include "Serializer.hpp"


int main()
{
    Data d;
    d.str = "str";
    Data *dp = &d;

    std::cout << "dp\t\t: " << dp << std::endl;

    uintptr_t t = Serializer::serialize(dp);
    std::cout << "uintptr_t\t: " << t << std::endl;
    

    dp = Serializer::deserialize(t);
    std::cout << "dp2\t\t: " << dp << std::endl;
    std::cout << "dp in\t\t: " << dp->str << std::endl;
}
