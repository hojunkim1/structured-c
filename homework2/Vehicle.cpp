#include "Vehicle.h"

Vehicle::Vehicle() : manufacturerName(""), numCylinders(0), owner(Person())
{
    // 의도적인 공백
}

Vehicle::Vehicle(string theManufacturerName, int theNumCylinders, const Person &theOwner)
    : manufacturerName(theManufacturerName), numCylinders(theNumCylinders), owner(theOwner)
{
    // 의도적인 공백
}

Vehicle::Vehicle(const Vehicle &theObject)
    : manufacturerName(theObject.getManufacturerName()),
      numCylinders(theObject.getNumCylinders()),
      owner(theObject.getOwner())
{
    // 의도적인 공백
}

Vehicle &Vehicle::operator=(const Vehicle &rtSide)
{
    manufacturerName = rtSide.getManufacturerName();
    numCylinders = rtSide.getNumCylinders();
    owner = rtSide.getOwner();
    return *this;
}
