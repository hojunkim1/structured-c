#include <iostream>

class Money
{
private:
    int dollars;
    int cents;

public:
    Money();
    Money(int dollars, int cents);
    int getDollars() const;
    double getCents() const;
    void setDollars(int dollars);
    void setCents(int cents);
    double getTotal() const;
};

int main()
{
    Money m1;
    m1.setDollars(30);
    m1.setCents(44);
    std::cout << "Total: " << m1.getTotal() << std::endl;

    Money m2(10, 50);
    std::cout << "Total: " << m2.getTotal() << std::endl;

    return 0;
}

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
    return dollars + (static_cast<double>(cents) / 100);
}
