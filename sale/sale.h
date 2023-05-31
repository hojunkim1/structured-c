#ifndef SALE_H
#define SALE_H

namespace SavitchSale
{
    class Sale
    {
    public:
        Sale();
        Sale(double thePrice);
        double getPrice() const;
        void setPrice(double newPrice);
        virtual double bill() const;
        double saving(const Sale &other) const;
        // 호출 객체 대신에 다른 것을 사면 saving를 반환한다.
    private:
        double price;
    };

    bool operator<(const Sale &first, const Sale &second);

} // SavitchSale

#endif // SALE_H
