#include <iostream>
#include "sale.h"
#include "discountsale.h"
using std::cout;
using std::endl;
using std::ios;
using namespace SavitchSale;

int main()
{
    Sale simple(10.00);               // 1개에 $10.00
    DiscountSale discount(11.00, 10); // 1개에 $11.00이고 10% 할인이다.

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    if (discount < simple)
    {
        cout << "Discounted item is cheaper.\n"
             << "Saving is $" << simple.saving(discount) << endl;
    }
    else
        cout << "Discounted item is not cheaper.\n";

    return 0;
}
