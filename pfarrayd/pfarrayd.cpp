#include <iostream>
#include "pfarrayd.h"
using std::cout;

PFArrayD::PFArrayD() : capacity(50), used(0)
{
    a = new double[capacity];
}

PFArrayD::PFArrayD(int capacityValue) : capacity(capacityValue), used(0)
{
    a = new double[capacity];
}

PFArrayD::PFArrayD(const PFArrayD &pfaObject)
    : capacity(pfaObject.getCapacity()), used(pfaObject.getNumberUsed())
{
    a = new double[capacity];
    for (int i = 0; i < used; i++)
        a[i] = pfaObject.a[i];
}

void PFArrayD::addElement(double element)
{
    if (used >= capacity)
    {
        cout << "Attempt to exceed capacity in PEArrayD.\n";
        exit(0);
    }
    a[used] = element;
    used++;
}

double &PFArrayD::operator[](int index)
{
    if (index >= used)
    {
        cout << "Illegal index in PEArrayD.\n";
        exit(0);
    }

    return a[index];
}

PFArrayD &PFArrayD::operator=(const PFArrayD &rightSide)
{
    if (capacity != rightSide.capacity)
    {
        delete[] a;
        a = new double[rightSide.capacity];
    }

    capacity = rightSide.capacity;
    used = rightSide.used;
    for (int i = 0; i < used; i++)
        a[i] = rightSide.a[i];

    return *this;
}

PFArrayD::~PFArrayD()
{
    delete[] a;
}
