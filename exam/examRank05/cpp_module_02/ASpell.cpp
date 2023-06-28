#include "ASpell.hpp"

ASpell::ASpell(){}

ASpell::ASpell(const std::string name, const std::string effects)
	: _name(name), _effects(effects)
{}

ASpell::~ASpell(){}

ASpell::ASpell(const ASpell& copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_effects = copy._effects;
	}
}

const ASpell& ASpell::operator=(const ASpell& copy){
	if (this != &copy)
	{
		_name = copy._name;
		_effects = copy._effects;
	}
	return *this;
}

const std::string ASpell::getEffects()const
{
	return (_effects);
}

const std::string ASpell::getName() const
{
	return _name;
}

void ASpell::launch(const ATarget& target)
{
	target.getHitBySpell(*this);
}
