#include "Truck.h"

Truck::Truck() : Vehicle(), loadCapacity(0), towingCapacity(0)
{
}

Truck::Truck(string manufacturerName, int numCylinders, const Person &owner,
             double loadCapacity, int towingCapacity)
    : Vehicle(manufacturerName, numCylinders, owner),
      loadCapacity(loadCapacity), towingCapacity(towingCapacity)
{
}

Truck::Truck(const Truck &truck)
    : Vehicle(truck.getManufacturerName(), truck.getNumCylinders(), truck.getOwner()),
      loadCapacity(truck.getLoadCapacity()), towingCapacity(truck.getTowingCapacity())
{
}

double Truck::getLoadCapacity() const
{
    return this->loadCapacity;
}

int Truck::getTowingCapacity() const
{
    return this->towingCapacity;
}

Truck &Truck::operator=(const Truck &operand)
{
    this->loadCapacity = operand.getLoadCapacity();
    this->towingCapacity = operand.getTowingCapacity();
    return *this;
}
