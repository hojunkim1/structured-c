#include <iostream>
#include <string>
#include "salariedemployee.h"
using std::cout;
using std::endl;
using std::string;

namespace SavitchEmployees
{
    SalariedEmployee::SalariedEmployee() : Employee(), salary(0)
    {
        // 의도적인 공백
    }

    SalariedEmployee::SalariedEmployee(
        const string &theName, const string &theSsn, double theWeeklySalary)
        : Employee(theName, theSsn), salary(theWeeklySalary)
    {
        // 의도적인 공백
    }

    double SalariedEmployee::getSalary() const
    {
        return salary;
    }

    void SalariedEmployee::setSalary(double newSalary)
    {
        salary = newSalary;
    }

    void SalariedEmployee::printCheck()
    {
        setNetPay(salary);

        cout << "\n----------------------------------------\n"
             << "Pay to the order of " << getName() << endl
             << "The sum of " << getNetPay() << "Dollars\n"
             << "Check Stub: NOT NEGOTIABLE\n"
             << "EMPLOYEE NUMBER: " << getSsn() << endl
             << "Salaried Employee. Regular Pay: " << salary << endl
             << "----------------------------------------\n";
    }

} // SavitchEmployees
