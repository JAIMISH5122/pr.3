#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int id;

public:
    static int count;

    Vehicle(int i)
    {
        id = i;
        count++;
    }

    virtual void show()
    {
        cout << "Vehicle ID: " << id << endl;
    }

    ~Vehicle() {}
};

int Vehicle::count = 0;

class Car : public Vehicle
{
public:
    Car(int i) : Vehicle(i) {}

    void show()
    {
        cout << "Car ID: " << id << endl;
    }
};

class ElectricCar : public Car
{
public:
    ElectricCar(int i) : Car(i) {}

    void show()
    {
        cout << "Electric Car ID: " << id << endl;
    }
};

class Aircraft
{
public:
    int range;

    Aircraft(int r)
    {
        range = r;
    }
};

class FlyingCar : public ElectricCar, public Aircraft
{
public:
    FlyingCar(int i, int r) : ElectricCar(i), Aircraft(r) {}

    void show()
    {
        cout << "Flying Car ID: " << id << " Range: " << range << endl;
    }
};

class Sedan : public Car
{
public:
    Sedan(int i) : Car(i) {}
};

class SUV : public Car
{
public:
    SUV(int i) : Car(i) {}
};

int main()
{
    Sedan s(1);
    SUV u(2);
    FlyingCar f(3, 500);

    s.show();
    u.show();
    f.show();

    cout << "Total Vehicles: " << Vehicle::count << endl;
    
}
