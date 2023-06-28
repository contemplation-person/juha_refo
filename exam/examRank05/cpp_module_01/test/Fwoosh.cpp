#include "Fwoosh.hpp"


Fwoosh::Fwoosh()
	: ASpell::ASpell("Fwoosh", "fwooshed")
{}

Fwoosh::Fwoosh(const std::string name, const std::string effects)
	: ASpell::ASpell(name, effects)
{}

Fwoosh::~Fwoosh(){}

Fwoosh::Fwoosh(const Fwoosh& copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_effects = copy._effects;
	}
}

const Fwoosh& Fwoosh::operator=(const Fwoosh& copy){
	if (this != &copy)
	{
		_name = copy._name;
		_effects = copy._effects;
	}
	return *this;
}

const ASpell* Fwoosh::clone()
{
	return new Fwoosh(_name, _effects);
}

