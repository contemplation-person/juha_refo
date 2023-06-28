#ifndef __ATAR__
#define __ATAR__

#include <iostream>
#include "ASpell.hpp"
class ASpell;
class ATarget
{
public:
	ATarget();
	ATarget(const std::string type);
	virtual ~ATarget();
	ATarget(const ATarget& copy);
	const ATarget& operator=(const ATarget& copy);
	const std::string& getType() const;

	virtual ATarget* clone()const = 0;

	void getHitBySpell(const ASpell& spell)const;

protected:
	std::string _type;

};

#endif
