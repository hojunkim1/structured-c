#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle
{
public:
    Truck();
    Truck(string manufacturerName, int numCylinders, const Person &owner,
          double loadCapacity, int towingCapacity);
    Truck(const Truck &truck);
    double getLoadCapacity() const;
    int getTowingCapacity() const;
    Truck &operator=(const Truck &operand);

private:
    double loadCapacity;
    int towingCapacity;
};

#endif // TRUCK_H
