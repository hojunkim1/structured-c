#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;

namespace SavitchEmployees
{
    class Employee
    {
    public:
        Employee();
        Employee(const string &theName, const string &theSsn);
        string getName() const;
        string getSsn() const;
        double getNetPay() const;
        void setName(const string &newName);
        void setSsn(const string &newSsn);
        void setNetPay(double newNetPay);
        virtual void printCheck() const = 0;

    private:
        string name;
        string ssn;
        double netPay;
    };

} // SavitchEmployees

#endif // EMPLOYEE_H
