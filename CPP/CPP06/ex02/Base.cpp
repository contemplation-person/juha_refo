#include "Base.hpp"
#include <cstdlib>
#include <iostream>

Base::~Base(){}
A::~A(){}
B::~B(){}

Base * generate(void)
{
	int i = rand() % 3;
	switch (i)
	{
	case 0:
		return new A;
	case 1:
		return new B;
	default:
		return new C;
	}
}

void identify(Base *p)
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "Pointer: A" << std::endl;
	else if (b)
		std::cout << "Pointer: B" << std::endl;
	else
		std::cout << "Pointer: C" << std::endl;
}

void identify(Base &p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "Reference: A" << std::endl;
	} catch (std::bad_cast) {
	}
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "Reference: B" << std::endl;
	} catch (std::bad_cast) {
	}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "Reference: C" << std::endl;
	} catch (std::bad_cast) {
	}
}
