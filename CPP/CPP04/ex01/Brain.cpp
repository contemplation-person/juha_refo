#include "Brain.hpp"
Brain::Brain() 
{ 
    ideas[0] = "NULL";
    std::cout << "create brain" << std::endl; 
};

Brain::~Brain() { };

void Brain::printIdeas()
{
    std::cout << ideas[0] << std::endl;
}

void Brain::setIdeas(std::string str)
{
    ideas[0] = str;
}
