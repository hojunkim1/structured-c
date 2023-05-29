#include <string>
#include <cstdlib>
#include <iostream>
#include "employee.h"
using std::cout;
using std::string;

namespace SavitchEmployees
{
    Employee::Employee() : name("No name yet"), ssn("No number yet"), netPay(0)
    {
        // 의도적인 공백
    }

    Employee::Employee(const string &theName, const string &theSsn)
        : name(theName), ssn(theSsn), netPay(0)
    {
        // 의도적인 공백
    }

    string Employee::getName() const
    {
        return name;
    }

    string Employee::getSsn() const
    {
        return ssn;
    }

    double Employee::getNetPay() const
    {
        return netPay;
    }

    void Employee::setName(const string &newName)
    {
        name = newName;
    }

    void Employee::setSsn(const string &newSsn)
    {
        ssn = newSsn;
    }

    void Employee::setNetPay(double newNetPay)
    {
        netPay = newNetPay;
    }

    void Employee::printCheck() const
    {
        cout << "\nERROR: printCheck FUNCTION CALLED FOR AN \n"
             << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
             << "Check with the author of the program about this bug.\n";
        exit(1);
    }

} // SavitchEmployees
