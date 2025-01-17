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

void    Warlock::learnSpell(ASpell *obj)
{
    book[obj->getName()] = obj;
}

void    Warlock::forgetSpell(std::string name)
{
    std::map<std::string, ASpell*>::iterator it = book.find(name);
    if (it != book.end())
        book.erase(name);
}

void    Warlock::launchSpell(std::string name, ATarget const &obj)
{
    std::map<std::string, ASpell*>::iterator it = book.find(name);
    if (it != book.end())
        obj.getHitBySpell(*(it->second));
}