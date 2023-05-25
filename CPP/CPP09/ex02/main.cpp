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
    std::vector<int> vector;
    std::deque<int> deque;
    std::clock_t time[2][2];


    try
    {
        time[VECTOR][T_START] = std::clock();
        parse(input, vector);
        sort(vector);
        time[VECTOR][T_END] = std::clock();


        time[DEQUE][T_START] = std::clock();
        parse(input, deque);
        sort(deque);
        time[DEQUE][T_END] = std::clock();
        printResult(input, vector, time);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    

}
