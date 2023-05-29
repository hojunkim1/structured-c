#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using std::istream;
using std::ostream;
using std::string;

class Person
{
public:
    Person();
    Person(string theName);
    Person(const Person &theObject);
    string getName() const;
    Person &operator=(const Person &rtSide);
    friend istream &operator>>(istream &inStream, Person &personObject);
    friend ostream &operator<<(ostream &outStream, const Person &personObject);

private:
    string name;
};

#endif // PERSON_H
