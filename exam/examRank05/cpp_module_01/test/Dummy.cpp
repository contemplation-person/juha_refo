#include "Dummy.hpp"

Dummy::Dummy()
	:ATarget("Target Practice Dummy")
{}

Dummy::Dummy(const std::string type)
	:ATarget::ATarget(type)
{}

Dummy::~Dummy(){}

Dummy::Dummy(const Dummy& copy)
{
	if (this != &copy)
	{
		_type = copy._type;
	}
}

const Dummy& Dummy::operator=(const Dummy& copy){
	if (this != &copy)
	{
		_type = copy._type;
	}
	return *this;
}

Dummy* Dummy::clone() const 
{
	return new Dummy("Target Practice " + _type);//
}

