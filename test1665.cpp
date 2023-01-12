#include <iostream>
using namespace std;

// 成员函数 + 成员变量
// 学生类

// 私有的
class student {
    public:
        // 构造函数 -》 初始化函数    【】   类名
        student() {
            age = 100;
            ID = 13124324;
        }
    
        // 析构
        ~student() {
            
        }

    // 成员函数 
    void say() {
        cout << "hahah我今年：" << ID << endl;
    }

    // 成员变量
    int ID;
    char* name;
    int age;
};

int main() {
    student s1;
    s1.say();

    return 0;
}

