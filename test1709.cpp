#include <iostream>
#include <deque>
#include <vector>
#include <list>
using namespace std;

namespace foxny {
    template<class T, class Container = deque<T>> 
    class stack {
        public:
            void push(const T& x) {
                _con.push_back(x);    // 对于栈而言，入栈就是尾插
            }
            void pop() {
                _con.pop_back();     // 对于栈而言，出栈就是尾删
            }
            const T& top() {
                return _con.back();  // 返回尾上数据
            }
            size_t size() {
                return _con.size();  // 返回大小
            }
            bool empty() {
                return _con.empty(); // 返回是否为空
            }

        private:
            Container _con;
    };

    void test_stack1() {
        stack<int> st;
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);

        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();   
        }
        cout << endl;
    }

    void test_stack2() {
        stack<int, vector<int>> st;  // 我想默认用 vector
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);

        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();   
        }
        cout << endl;
    }

    void test_stack3() {
        stack<int, list<int>> st;  // 我想默认用 list
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);

        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();   
        }
        cout << endl;
    }
}

int main(void)
{
    foxny::test_stack1();
    foxny::test_stack2();
    foxny::test_stack3();

    return 0;
}


