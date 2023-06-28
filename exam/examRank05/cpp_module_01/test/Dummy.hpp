#ifndef __DUMM__
#define  __DUMM__

#include "ATarget.hpp"

class Dummy : public ATarget
{
public:
	Dummy();
	Dummy(const std::string type);
	~Dummy();
	Dummy(const Dummy& copy);
	const Dummy& operator=(const Dummy& copy);

	virtual Dummy* clone()const;

};

#endif
