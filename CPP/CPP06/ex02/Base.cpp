#include "Base.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

Base::~Base(){}
A::~A(){}
B::~B(){}
C::~C(){}

Base * generate(void)
{
    std::srand(time(NULL));
    int i = std::rand() % 3;
	switch (i)
	{
	case 0:
		return (new A());
	case 1:
		return (new B());
	default:
		return (new C());
	}
}

void identify(Base *p)
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "Pointer\t\t: A - " << a << std::endl;
	else if (b)
		std::cout << "Pointer\t\t: B - " << b << std::endl;
	else
		std::cout << "Pointer\t\t: C - " << c << std::endl;
}

void identify(Base &p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		std::cout << "Reference\t: A - " << &a << std::endl;
	} catch (std::bad_cast) {
	}
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "Reference\t: B - " << &b << std::endl;
	} catch (std::bad_cast) {
	}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "Reference\t: C - " << &c << std::endl;
	} catch (std::bad_cast) {
	}
}
