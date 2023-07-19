#ifndef __WARLOCK_HPP__
#define __WARLOCK_HPP__

#include <iostream>

class Warlock
{
public:
	Warlock(const std::string& name, 
			const std::string& title);
	virtual ~Warlock();
	const std::string getName() const;
	const std::string getTitle() const;
	void setTitle(const std::string& title);
	void setName(const std::string& name);
	void introduce() const;

private:
	Warlock();
	Warlock(const Warlock& warlock);
	Warlock& operator=(const Warlock& warlock);
	std::string name;
	std::string title;
};
#endif