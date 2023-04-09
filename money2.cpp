#include <iostream>
using namespace std;
#include "money2.h"

Money::Money() : total(0)
{
}

Money::Money(int dollars, int cents)
    : total(dollars + ((double)cents / 100))
{
}

int Money::getDollars() const
{
    return (int)total;
}

double Money::getCents() const
{
    return (total - (int)total) * 100;
}

void Money::setDollars(int myDollars)
{
    double cents = getCents();
    total = myDollars + (cents / 100);
}

void Money::setCents(int myCents)
{
    int dollars = getDollars();
    total = dollars + ((double)myCents / 100);
}

double Money::getTotal() const
{
    return total;
}

int main()
{
    Money m1;
    m1.setDollars(10);
    m1.setCents(50);
    cout << "Total: " << m1.getTotal() << endl;

    Money m2(30, 44);
    cout << "Total: " << m2.getTotal() << endl;

    return 0;
}
