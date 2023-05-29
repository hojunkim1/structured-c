#include "Person.h"

Person::Person() : name("")
{
}

Person::Person(string theName) : name(theName)
{
}

Person::Person(const Person &theObject) : name(theObject.getName())
{
}

string Person::getName() const
{
    return this->name;
}

Person &Person::operator=(const Person &rtSide)
{
    this->name = rtSide.getName();
    return *this;
}

istream &operator>>(istream &inStream, Person &personObject)
{
    return inStream >> personObject.name;
}

ostream &operator<<(ostream &outStream, const Person &personObject)
{
    return outStream << personObject.getName();
}
