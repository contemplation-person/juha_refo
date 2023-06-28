#pragma once

#include "ATarget.hpp"
#include <iostream>
#include <vector>

class Warlock
{
    private:
        std::string name;
        std::string title;
		std::vector<const ASpell *> _spell;

        Warlock();
        Warlock(Warlock const &other);
        Warlock &operator=(Warlock const &other);
    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();

        std::string const &getName() const;
        std::string const &getTitle() const;

        void setTitle(std::string const &title);

        void introduce() const;

		void learnSpell(const ASpell* spell);
		void forgetSpell(const std::string& spellName);
		void launchSpell(const std::string& spellName, const ATarget& target);
};

