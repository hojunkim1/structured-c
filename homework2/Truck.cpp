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
    : Vehicle(theObject.getManufacturerName(), theObject.getNumCylinders(), theObject.getOwner()),
      loadCapacity(theObject.getLoadCapacity()), towingCapacity(theObject.getTowingCapacity())
{
    // 의도적인 공백
}

Truck &Truck::operator=(const Truck &rtSide)
{
    manufacturerName = rtSide.getManufacturerName();
    numCylinders = rtSide.getNumCylinders();
    owner = rtSide.getOwner();
    loadCapacity = rtSide.getLoadCapacity();
    towingCapacity = rtSide.getTowingCapacity();
    return *this;
}
