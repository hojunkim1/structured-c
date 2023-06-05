#include "Truck.h"

Truck::Truck() : Vehicle(), loadCapacity(0), towingCapacity(0)
{
    // 의도적인 공백
}

Truck::Truck(string theManufacturerName, int theNumCylinders, const Person &theOwner,
             double theLoadCapacity, int theTowingCapacity)
    : Vehicle(theManufacturerName, theNumCylinders, theOwner),
      loadCapacity(theLoadCapacity), towingCapacity(theTowingCapacity)
{
    // 의도적인 공백
}

Truck::Truck(const Truck &theObject)
    : Vehicle(theObject.manufacturerName, theObject.numCylinders, theObject.owner),
      loadCapacity(theObject.loadCapacity), towingCapacity(theObject.towingCapacity)
{
    // 의도적인 공백
}

Truck &Truck::operator=(const Truck &rtSide)
{
    manufacturerName = rtSide.manufacturerName;
    numCylinders = rtSide.numCylinders;
    owner = rtSide.owner;
    loadCapacity = rtSide.loadCapacity;
    towingCapacity = rtSide.towingCapacity;
    return *this;
}
