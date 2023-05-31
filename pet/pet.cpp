#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Pet
{
public:
    string name;
    virtual void print() const;
};

class Dog : public Pet
{
public:
    string breed;
    virtual void print() const;
};

int main()
{
    Dog vdog;
    Pet vpet;
    vdog.name = "Tiny";
    vdog.breed = "Great Dane";
    vpet = vdog;
    cout << "The slicing problen:\n";
    // vpet.print(); 은 클래스 Pet이 breed라는 이름의 멤버를 가지지 않기 때문에 적법하지 않다.
    vpet.print();
    cout << "Note that it was print from Pet that was invoked.\n";

    cout << "The slicing problem defeated:\n";
    Pet *ppet;
    Dog *pdog;
    pdog = new Dog;
    pdog->name = "Tiny";
    pdog->breed = "Great Dane";
    ppet = pdog;
    ppet->print();
    pdog->print();

    return 0;
}

void Dog::print() const
{
    cout << "name: " << name << endl;
    cout << "breed: " << breed << endl;
}

void Pet::print() const
{
    cout << "name: " << name << endl;
}
