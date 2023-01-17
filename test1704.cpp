#include <iostream>
using namespace std;

// override

class Car {
public:
    virtual void Drive() {
        cout << "Car:Drive()" << endl;
    }
};

class Benz : public Car {
public:
    virtual void Drive() override {
        cout << "Benz:Drive()" << endl;
    }
};

int main(void)
{
    Benz b;
    b.Drive();

    Car c;
    c.Drive();

    return 0;
}
