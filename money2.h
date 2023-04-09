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
