#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << "\033[37m";
    const Animal* j = new Dog();
    delete j;//should not create a leak
    std::cout << "\033[31m";
    const Animal* i = new Cat();
    delete i;

    const Animal* test[10];
    for (int i = 0; i < 10; i++)
    {
        if (i > 4)
        {
            std::cout << "\033[32m";
            test[i] = new Cat();
        }
        else
        {
            std::cout << "\033[33m";
            test[i] = new Dog();
        }
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << "\033[34m";
        delete test[i];
    }

    Cat t;
    Cat c;
    t = c;
    system("leaks Animal");

    return 0;
}
