#include "discountsale.h"

namespace SavitchSale
{
    DiscountSale::DiscountSale() : Sale(), discount(0)
    {
        // 의도적인 공백
    }

    DiscountSale::DiscountSale(double thePrice, double theDiscount)
        : Sale(thePrice), discount(theDiscount)
    {
        // 의도적인 공백
    }

    double DiscountSale::getDiscount() const
    {
        return discount;
    }

    void DiscountSale::setDiscount(double newDiscount)
    {
        discount = newDiscount;
    }

    double DiscountSale::bill() const
    {
        double fraction = discount / 100;
        return (1 - fraction) * getPrice();
    }

} // SavitchSale
