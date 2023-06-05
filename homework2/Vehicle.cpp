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
    : manufacturerName(theObject.manufacturerName),
      numCylinders(theObject.numCylinders),
      owner(theObject.owner)
{
    // 의도적인 공백
}

Vehicle &Vehicle::operator=(const Vehicle &rtSide)
{
    manufacturerName = rtSide.manufacturerName;
    numCylinders = rtSide.numCylinders;
    owner = rtSide.owner;
    return *this;
}
