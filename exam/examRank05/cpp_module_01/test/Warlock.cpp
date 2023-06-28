#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() {std::cout << this->name << ": My job here is done!\n";}

std::string const &Warlock::getName() const { return (this->name);}
std::string const &Warlock::getTitle() const { return (this->title);}

void Warlock::setTitle(std::string const &title) { this->title = title;}

void Warlock::introduce() const { std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";}

void Warlock::learnSpell(const ASpell* spell)
{
	std::vector<const ASpell *>::iterator it;

	for (it = _spell.begin(); it != _spell.end(); it++)
	{
		if ((*it)->getName() == spell->getName())
		{
			delete spell;
			return;
		}
	}
	_spell.push_back(spell);
	// std::cout << _spell.size() << std::endl;
	// std::cout << _spell[0]->getName() << std::endl;
}
void Warlock::forgetSpell(const std::string& spellName)
{
	std::vector<const ASpell *>::iterator it;
	for (it = _spell.begin(); it != _spell.end(); it++)
	{
		if ((*it)->getName() == spellName)
		{
			delete *it;
			_spell.erase(it);
			return;
		}
	}
}

void Warlock::launchSpell(const std::string& spellName, const ATarget& target) 
{
	std::vector<const ASpell *>::iterator it;

	for (it = _spell.begin(); it != _spell.end(); it++)
	{
		if ((*it)->getName() == spellName)
		{
			target.getHitBySpell(**it);
			return;
		}
	}
}
