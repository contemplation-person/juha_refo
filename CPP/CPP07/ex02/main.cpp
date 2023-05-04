#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750


/*
class test
{
public:
    test() : t(5){ };
    int getterTest(){ std::cout << this->t << std::endl;return this->t;};

private:
    int t;
};
*/

int main(int, char**)
{
    //임의 class로 해볼것.
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    (void )mirror;
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    /*
    Array<test> te(1);

    te[0].getterTest();
    */
    return 0;
}
