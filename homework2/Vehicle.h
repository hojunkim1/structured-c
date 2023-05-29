#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "Person.h"
using std::string;

class Vehicle
{
public:
    Vehicle();
    Vehicle(string theManufacturerName, int theNumCylinders, const Person &theOwner);
    Vehicle(const Vehicle &theObject);
    string getManufacturerName() const { return manufacturerName; };
    int getNumCylinders() const { return numCylinders; };
    Person getOwner() const { return owner; };
    Vehicle &operator=(const Vehicle &rtSide);

protected:
    string manufacturerName;
    int numCylinders;
    Person owner;
};

#endif // VEHICLE_H
