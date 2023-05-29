#ifndef TRUCK_H
#define TRUCK_H

#include <string>
#include "Person.h"
#include "Vehicle.h"
using std::string;

class Truck : public Vehicle
{
public:
    Truck();
    Truck(string theManufacturerName, int theNumCylinders, const Person &theOwner,
          double theLoadCapacity, int theTowingCapacity);
    Truck(const Truck &theObject);
    double getLoadCapacity() const { return loadCapacity; };
    int getTowingCapacity() const { return towingCapacity; };
    Truck &operator=(const Truck &rtSide);

private:
    double loadCapacity;
    int towingCapacity;
};

#endif // TRUCK_H
