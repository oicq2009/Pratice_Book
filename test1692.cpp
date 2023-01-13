#include <iostream>
using namespace std;

class A {
public:
    void fun() {
        cout <<  "func()" << endl;
    }
};

class B : public A {
public:
    void fun() {
        cout << "func(int i) -> " << endl;
    }
};



int main()
{
    B b;
    b.fun();


    return 0;
}


