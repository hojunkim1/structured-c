#ifndef VEHICLE_H
#define VEHICLE_H

#include "Person.h"

class Vehicle
{
public:
    Vehicle();
    Vehicle(string manufacturerName, int numCylinders, const Person &owner);
    Vehicle(const Vehicle &vehicle);
    string getManufacturerName() const;
    int getNumCylinders() const;
    Person getOwner() const;
    Vehicle &operator=(const Vehicle &operand);

private:
    string manufacturerName;
    int numCylinders;
    Person owner;
};

#endif // VEHICLE_H
