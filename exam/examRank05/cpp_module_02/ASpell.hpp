#ifndef __ASP__
#define __ASP__

#include <iostream>
#include "ATarget.hpp"
class ATarget;
class ASpell
{
public:
	ASpell();
	ASpell(const std::string name, const std::string effects);
	virtual ~ASpell();
	ASpell(const ASpell& copy);
	const ASpell& operator=(const ASpell& copy);

	const std::string getEffects()const;
	const std::string getName() const;
	void launch(const ATarget& target);

	virtual const ASpell* clone() = 0;

protected:
	std::string _name;
	std::string _effects;

};

#endif
