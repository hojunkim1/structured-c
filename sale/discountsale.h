#ifndef DISCOUNTSALE_H
#define DISCOUNTSALE_H

#include "sale.h"

namespace SavitchSale
{
    class DiscountSale : public Sale
    {
    public:
        DiscountSale();
        DiscountSale(double thePrice, double theDiscount);
        // Discount의 가격의 백분율로 표현된다.
        // 음의 할인은 가격 인상이다.
        double getDiscount() const;
        void setDiscount(double newDiscount);
        double bill() const;

    private:
        double discount;
    };

} // SavitchSale

#endif // DISCOUNTSALE_H