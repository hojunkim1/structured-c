#include "Person.h"

Person::Person() : name("")
{
    // 의도적인 공백
}

Person::Person(string theName) : name(theName)
{
    // 의도적인 공백
}

Person::Person(const Person &theObject) : name(theObject.name)
{
    // 의도적인 공백
}

Person &Person::operator=(const Person &rtSide)
{
    name = rtSide.name;
    return *this;
}

istream &operator>>(istream &inStream, Person &personObject)
{
    return inStream >> personObject.name;
}

ostream &operator<<(ostream &outStream, const Person &personObject)
{
    return outStream << personObject.name;
}
