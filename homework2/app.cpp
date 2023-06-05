#include <iostream>
#include "Truck.h"
using std::cin;
using std::cout;
using std::endl;

void printTruckInfo(Truck &truck);

int main()
{
    Truck t1;
    cout << "Truck 1 info" << endl;
    printTruckInfo(t1);

    Person hojun;
    cout << "Your name: ";
    cin >> hojun;

    Truck t2("Volvo", 8, hojun, 80, 3);
    cout << "Truck 2 info" << endl;
    printTruckInfo(t2);

    Truck t3(t2);
    cout << "Truck 3 info" << endl;
    printTruckInfo(t3);

    Truck t4 = t3;
    cout << "Truck 4 info" << endl;
    printTruckInfo(t4);

    return 0;
}

void printTruckInfo(Truck &truck)
{
    cout << "Manufacture name: " << truck.getManufacturerName() << endl
         << "Cylinders number: " << truck.getNumCylinders() << endl
         << "Owner name: " << truck.getOwner() << endl
         << "Load capacity: " << truck.getLoadCapacity() << endl
         << "Towing capacity: " << truck.getTowingCapacity() << endl;
    cout << endl;
}
