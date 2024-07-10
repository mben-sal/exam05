#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class   Warlock
{
    private:
        std::string _name;
        std::string _title;
        SpellBook   sbook;
    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();
       	std::string const &getName() const;
        std::string const &getTitle() const;
        void    setTitle(const std::string &title);
        void    introduce() const;
        void    learnSpell(ASpell *obj);
        void    forgetSpell(std::string name);
        void    launchSpell(std::string name, ATarget const &obj);
};