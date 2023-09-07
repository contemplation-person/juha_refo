#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bureaucrat;
    bureaucrat.setGrade(150);
    bureaucrat.decrement();
    bureaucrat.setGrade(1);
    bureaucrat.increment();
	return 0;
	
}
