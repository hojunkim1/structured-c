#include <string>
#include <iostream>
#include "hourlyemployee.h"
using std::cout;
using std::endl;
using std::string;

namespace SavitchEmployees
{
    HourlyEmployee::HourlyEmployee() : Employee(), wageRate(0), hours(0)
    {
        // 의도적인 공백
    }

    HourlyEmployee::HourlyEmployee(
        const string &theName, const string &theSsn,
        double theWageRate, double theHours)
        : Employee(theName, theSsn), wageRate(theWageRate), hours(theHours)
    {
        // 의도적인 공백
    }

    void HourlyEmployee::setRate(double newWageRate)
    {
        wageRate = newWageRate;
    }

    double HourlyEmployee::getRate() const
    {
        return wageRate;
    }

    void HourlyEmployee::setHours(double hoursWorked)
    {
        hours = hoursWorked;
    }

    double HourlyEmployee::getHours() const
    {
        return hours;
    }

    void HourlyEmployee::printCheck()
    {
        setNetPay(hours * wageRate);

        cout << "\n----------------------------------------\n"
             << "Pay to the order of " << getName() << endl
             << "The sum of " << getNetPay() << "Dollars\n"
             << "Check Stub: NOT NEGOTIABLE\n"
             << "EMPLOYEE NUMBER: " << getSsn() << endl
             << "Hourly Employee. \nHoursWorled: " << hours
             << " Rate: " << wageRate << " Pay: " << getNetPay() << endl
             << "----------------------------------------\n";
    }

} // SavitchEmployees
