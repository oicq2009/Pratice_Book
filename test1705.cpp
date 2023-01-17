#include <iostream>
using namespace std;

// 抽象类：纯虚函数
// 在虚函数后面写上 = 0，就是纯虚函数

// 抽象：不具体化，不具象化
// 具象就是对应显示，抽象就是对应虚拟层面。
// 抽象类，不能实例化出对象

class Car {
public:
    //virtual void Drive() = 0;

    // 纯虚函数的实现没有意义
    // error: pure-specifier on function-definition
    virtual void Drive() = 0 {
        cout << "Drive()" << endl; 
    }
};

class BMW : public Car {
public:
    virtual void Drive() {
        cout << "BMW-操控" << endl;
    }
};

class Benz : public Car {
public:
    virtual void Drive() {
        cout << "Benz-舒适" << endl;
    }

};

int main(void)
{
    // BMW b;  只要包含纯虚函数的类都叫抽象类，这里BMW继承了Car

    // Car c;
    // c.Drive();

    return 0;
}

