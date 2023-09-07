#include "Base.hpp"

int main()
{
    Base *b = generate();
    identify(b);
    identify(*b);
    delete b;
    return 0;
}
