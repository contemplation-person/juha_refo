#include "ATarget.hpp"

ATarget::ATarget(){}

ATarget::ATarget(const std::string type)
	:_type(type)
{}

ATarget::~ATarget(){}

ATarget::ATarget(const ATarget& copy)
{
	if (this != &copy)
	{
		_type = copy._type;
	}
}

const ATarget& ATarget::operator=(const ATarget& copy){
	if (this != &copy)
	{
		_type = copy._type;
	}
	return *this;
}

const std::string& ATarget::getType() const
{
	return _type;
}

void ATarget::getHitBySpell(const ASpell& spell) const
{
	std::cout << _type + " has been " + spell.getEffects() + "!" << std::endl;
}
