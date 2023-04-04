#include <iostream>

class Money
{
private:
    int dollars;
    int cents;

public:
    Money(int dollars, int cents);
    Money(int dollars);
    Money();
    int getDollars() const;
    int getCents() const;
    void setDollars(int dollars);
    void setCents(int cents);
    void input();
    void output() const;
    Money add(const Money &other) const;
    Money subtract(const Money &other) const;
    Money multiply(double factor) const;
    Money divide(double factor) const;
};

Money::Money(int dollars, int cents)
{
    this->dollars = dollars;
    this->cents = cents;
}

Money::Money(int dollars)
{
    this->dollars = dollars;
    this->cents = 0;
}

Money::Money()
{
    this->dollars = 0;
    this->cents = 0;
}

int Money::getDollars() const
{
    return this->dollars;
}

int Money::getCents() const
{
    return this->cents;
}

void Money::setDollars(int dollars)
{
    this->dollars = dollars;
}

void Money::setCents(int cents)
{
    this->cents = cents;
}

void Money::input()
{
    std::cout << "Enter dollars: ";
    std::cin >> this->dollars;
    std::cout << "Enter cents: ";
    std::cin >> this->cents;
}

void Money::output() const
{
    std::cout << this->dollars << "." << this->cents << std::endl;
}

Money Money::add(const Money &other) const
{
    Money result;
    result.dollars = this->dollars + other.dollars;
    result.cents = this->cents + other.cents;
    if (result.cents >= 100)
    {
        result.cents -= 100;
        result.dollars += 1;
    }
    return result;
}

Money Money::subtract(const Money &other) const
{
    Money result;
    result.dollars = this->dollars - other.dollars;
    result.cents = this->cents - other.cents;
    if (result.cents < 0)
    {
        result.cents += 100;
        result.dollars -= 1;
    }
    return result;
}

Money Money::multiply(double factor) const
{
    Money result;
    double totalCents = this->dollars * 100.0 + this->cents;
    totalCents *= factor;
    result.dollars = totalCents / 100;
    result.cents = totalCents - result.dollars * 100;
    return result;
}

Money Money::divide(double factor) const
{
    Money result;
    double totalCents = this->dollars * 100.0 + this->cents;
    totalCents /= factor;
    result.dollars = totalCents / 100;
    result.cents = totalCents - result.dollars * 100;
    return result;
}

int main(int argc, char const *argv[])
{
    Money m1(10, 9);
    Money m2(5, 99);
    Money m3 = m1.add(m2);
    Money m4 = m1.subtract(m2);
    Money m5 = m1.multiply(2);
    Money m6 = m1.divide(2);
    m3.output();
    m4.output();
    m5.output();
    m6.output();
    return 0;
}
