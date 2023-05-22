#include "PmergeMe.hpp"

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

    std::string input = makeString(argc, argv);
    // std::cout << input << std::endl;
    std::vector<int> vector;
    std::deque<int> deque;

    try
    {
        //check time value
        parse(input, vector);
        sort(vector);
        //check time value

        //check time value
        parse(input, deque);
/*
        sort(list);
        //check time value
        printResult(input, vector, list);
*/
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    

}
