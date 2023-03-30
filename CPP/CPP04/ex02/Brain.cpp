#include "Brain.hpp"

Brain::Brain() 
{ 
    std::cout << "create brain" << std::endl; 
}

Brain::~Brain() 
{ 
    std::cout << "delete Brain" << std::endl;
}

Brain& Brain::operator=(const Brain& brain)
{
    if (this != &brain)
    {
        for (int i = 0; i < 100; i++)
        {
            this->ideas[i] = brain.ideas[i];
        }
    }
    return *this;
}

Brain::Brain(const Brain& brain)
{
    *this = brain;
}
