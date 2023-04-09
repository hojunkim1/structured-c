#include <iostream>
using namespace std;
#include "money.h"

Money::Money() : dollars(0), cents(0)
{
}

Money::Money(int dollars, int cents)
    : dollars(dollars), cents(cents)
{
}

int Money::getDollars() const
{
    return dollars;
}

double Money::getCents() const
{
    return cents;
}

void Money::setDollars(int myDollars)
{
    dollars = myDollars;
}

void Money::setCents(int myCents)
{
    cents = myCents;
}

double Money::getTotal() const
{
    return dollars + ((double)cents / 100);
}

int main()
{
    Money m1;
    m1.setDollars(30);
    m1.setCents(44);
    cout << "Total: " << m1.getTotal() << endl;

    Money m2(10, 50);
    cout << "Total: " << m2.getTotal() << endl;

    return 0;
}
