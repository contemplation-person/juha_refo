#ifndef __ASPELL_HPP__
# define __ASPELL_HPP__
#include <string>

class ASpell
{
public:
	ASpell();
	ASpell(const ASpell &copy);
	ASpell &operator=(const ASpell &copy);
	ASpell(std::string name, std::string effects);
	virtual ~ASpell();

	const std::string &getName() const;
	const std::string &getEffects() const;
	virtual const ASpell *clone() const = 0;

protected:
	std::string _name;
	std::string _effects;

};

#endif