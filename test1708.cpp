#include <iostream>
#include <vector>
#include <functional>  // 这里放的是一些仿函数
#include <assert.h>
using namespace std;

namespace foxny {
    // less: 小于的比较
    template<class T> 
    struct less {
        bool operator()(const T& x, const T& y) const {
            return x < y;
        }
    };
    // greater: 大于的比较
    template<class T> 
    struct greater {
        bool operator()(const T& x, const T& y) const {
            return x > y;
        }
    };

    template<class T, class Container = vector<T>, class Compare = less<T>>
    class priority_queue {
        Compare _cmpFunc;
    public:
        // 创造空的优先级队列
        priority_queue()
            : _con()
        {}

        // 迭代器
        template<class InputIterator>
        priority_queue (InputIterator first, InputIterator last) 
            : _con(first, last)
        {
            while (first != last) {
                _con.push_back(*first++);
            }
  
            for (int father = (_con.size()-1-1) / 2; father >= 0; father++) {
                AdjustDown(father);
            }
        }

        /* 向上调整算法 */
        void AdjustUp(size_t child) {
            Compare cmpFunc;

            size_t father = (child - 1) / 2;
            while (child > 0) {
                // if (_con[father] < _con[child]) {
                if (cmpFunc(_con[father], _con[child])) {
                    swap(_con[father], _con[child]);
                    child = father;
                    father = (child - 1) / 2;
                }
                else {
                    break;
                }
            }
        }
        /* 向下调整算法 */
        void AdjustDown(size_t father) {
            Compare cmpFunc;

            size_t child = father * 2 + 1; // 默认认为左孩子大
            while (child < _con.size()) {
                // if (child + 1 < _con.size() && _con[child] < _con[child + 1]) {
                if (child + 1 < _con.size() && cmpFunc(_con[child], _con[child + 1])) {
                    child += 1;
                }

                // if (_con[father] < _con[child]) {
                if (cmpFunc(_con[father], _con[child])) {
                    swap(_con[father], _con[child]);
                    father = child;
                    child = father * 2 + 1;
                }
                else {
                    break;
                }
            }
        }

        /* 入数据 */
        void push(const T& x) {
            _con.push_back(x);
            AdjustUp(_con.size() - 1);
        }

        /* 出数据 */
        void pop() {
            assert(!_con.empty());
            swap(_con[0], _con[_con.size() - 1]);
            _con.pop_back();

            AdjustDown(0);
        }

        /* 返回堆顶数据 */
        const T& top() {
            return _con[0];
        }

        /* 返回大小 */
        size_t size() {
            return _con.size();
        }

        /* 判断是否为空 */
        bool empty() {
            return _con.empty();
        }

    private:
        Container _con;
    };

    // 小于比较，搞大堆
    void test_priority_queue1() {
        priority_queue<int> pQ;
        pQ.push(2);
        pQ.push(5);
        pQ.push(1);
        pQ.push(6);
        pQ.push(8);

        while (!pQ.empty()) {
            cout << pQ.top() << " ";
            pQ.pop();
        }
        cout << endl;
    }

    // 大于比较，搞小堆
    void test_priority_queue2() {
        priority_queue<int, vector<int>, greater<int>> pQ;
        pQ.push(2);
        pQ.push(5);
        pQ.push(1);
        pQ.push(6);
        pQ.push(8);

        while (!pQ.empty()) {
            cout << pQ.top() << " ";
            pQ.pop();
        }
        cout << endl;
    }

    void test_priority_queue3() {
        // TOP K
        int arr[] = {1,4,2,7,8,9};
        priority_queue<int> pQ(arr, arr + 6);  // 传一个迭代器区间
    }
}

int main(void)
{
    //foxny::test_priority_queue1();
    //foxny::test_priority_queue2();
    foxny::test_priority_queue3();

    return 0;
}

