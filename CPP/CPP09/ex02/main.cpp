#include "PmergeMe.hpp"
#include <iostream>

// using unsigned int;
// murge insert sort
// error input "2 2 1 4";
// program input is  3000

//print output
//Before
//After
// A sort name time and range

int main(int argc, char **argv) 
{
    while (argc < 2)
    {
        std::cout << "Please input a number" << std::endl;
        return 0;
    }

    std::string s = makeString(argc, argv);
    std::vector<int> v;
    std::list<int> l;

    try
    {
        parse(s, v);
        parse(s, l);
        //check time value
        sort(v);
        //check time value
        //check time value
        sort(l);
        //check time value
        printResult(s, v, l);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    

}
