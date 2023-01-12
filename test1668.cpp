#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

template<class T> 
class basic_string {
    public:
        basic_string(const T* str) {
            // 開空間存儲字符串，方便增刪查改
            size_t len = strlen(str);
            _str = new T[len + 1];
            strcpy(_str, str);
        }

        T& operator[](size_t pos) {
            assert(pos < _size);
            return _str[pos];
        }

    private:
        T* _str;
        size_t _size;
        size_t _capacity;
};

void test_string1() {
    string s("hello");
    s += ' ';
    s += "world";
    cout << s << endl;
}

void test_string2() {
    string s1("hello world");
    string s2("string");

    s1.swap(s2);   // 效率高
    swap(s1, s2);  // 效率低

    cout << s1 << endl;
    cout << s1.c_str() << endl;

    // 文件の後綴 取出
    string file("string.cpp");
    size_t pos = file.find('.');
    if (pos != string::npos) {
        string suffix = file.substr(pos, file.size() - pos);
        cout << file << "後綴:" << suffix << endl;
    } else {
        cout << "沒有後綴" << endl;
    }
}

int main(void) 
{
    test_string2();

    return (0);
}


