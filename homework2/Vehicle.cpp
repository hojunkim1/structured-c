#include "Vehicle.h"

Vehicle::Vehicle() : manufacturerName(""), numCylinders(0), owner(Person())
{
}

Vehicle::Vehicle(string manufacturerName, int numCylinders, const Person &owner)
    : manufacturerName(manufacturerName), numCylinders(numCylinders), owner(owner)
{
}

Vehicle::Vehicle(const Vehicle &vehicle)
    : manufacturerName(vehicle.getManufacturerName()),
      numCylinders(vehicle.getNumCylinders()),
      owner(vehicle.getOwner())
{
}

string Vehicle::getManufacturerName() const
{
    return this->manufacturerName;
}

int Vehicle::getNumCylinders() const
{
    return this->numCylinders;
}

Person Vehicle::getOwner() const
{
    return this->owner;
}

Vehicle &Vehicle::operator=(const Vehicle &operand)
{
    this->manufacturerName = operand.getManufacturerName();
    this->numCylinders = operand.getNumCylinders();
    this->owner = operand.getOwner();
    return *this;
}
