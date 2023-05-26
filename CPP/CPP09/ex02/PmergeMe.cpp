#include "PmergeMe.hpp"

std::string Function::makeString(int argc, char **argv)
{
	std::string str;

    for (int i = 1; i < argc; i++)
    {
        str+= argv[i];
        if (i != argc - 1)
            str+= " ";
    }
	return str;
}

void Function::printResult(std::string const& input, std::vector<int> const& vector, std::clock_t time[2][2])
{

	std::cout << "Before: " << input << std::endl;
	std::cout << "After: ";
	for (std::size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
	for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "\e[31mTime to process a range of \t " << vector.size() << " elements with std::vector\t: " 
			  << static_cast<double>(time[VECTOR][T_END] - time[VECTOR][T_START]) / CLOCKS_PER_SEC << " sec " << std::endl;
	std::cout << "Time to process a range of \t " << vector.size() << " elements with std::deque\t: "
			  << static_cast<double>(time[DEQUE][T_END] - time[DEQUE][T_START]) / CLOCKS_PER_SEC << " sec \e[0m"<< std::endl;

	for (std::size_t i = 0; i < vector.size() - 1; i++)
	{
		if (vector[i] > vector[i + 1])
		{
			std::cout << "vector[i] : " << vector[i];
			std::cout << " vector[i + 1] : " << vector[i + 1];
			std::cout << "  fail" << std::endl;
		}
	}
}
