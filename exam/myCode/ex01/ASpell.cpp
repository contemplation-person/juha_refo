#include "ASpell.hpp"

ASpell::ASpell() 
	: _name(""), _effects("")
{}

ASpell::ASpell(const ASpell &copy)
{
	if (this != &copy)
		*this = copy;
}

ASpell &ASpell::operator=(const ASpell &copy)
{
	if (this != &copy)
	{
		this->_name = copy._name;
		this->_effects = copy._effects;
	}
}

ASpell::ASpell(std::string name, std::string effects)
	: _name(name), _effects(effects)
{ }

ASpell::~ASpell()
{

}
const std::string &ASpell::getName() const
{
	return _name;
}

const std::string &ASpell::getEffects() const
{
	return _effects;
}