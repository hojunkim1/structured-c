#include <iostream>

class Money
{
private:
    double total;

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
    m1.setDollars(10);
    m1.setCents(50);
    std::cout << "Total: " << m1.getTotal() << std::endl;

    Money m2(30, 44);
    std::cout << "Total: " << m2.getTotal() << std::endl;

    return 0;
}

Money::Money() : total(0)
{
}

Money::Money(int dollars, int cents)
    : total(dollars + (static_cast<double>(cents) / 100))
{
}

int Money::getDollars() const
{
    return static_cast<int>(total);
}

double Money::getCents() const
{
    return (total - static_cast<int>(total)) * 100;
}

void Money::setDollars(int myDollars)
{
    double cents = getCents();
    total = myDollars + (cents / 100);
}

void Money::setCents(int myCents)
{
    int dollars = getDollars();
    total = dollars + (static_cast<double>(myCents) / 100);
}

double Money::getTotal() const
{
    return total;
}
