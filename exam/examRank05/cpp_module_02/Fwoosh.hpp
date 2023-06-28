#ifndef __FWOO__
#define  __FWOO__

#include "ASpell.hpp"

class Fwoosh:public ASpell
{
public:
	Fwoosh();
	Fwoosh(const std::string name, const std::string effects);
	~Fwoosh();
	Fwoosh(const Fwoosh& copy);
	const Fwoosh& operator=(const Fwoosh& copy);

	virtual const ASpell* clone();
};

#endif
