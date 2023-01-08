#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

namespace foxny {
    class string {
        public:
            /* 全缺省建構函式 */
            string(const char* str = "") 
                : _size(strlen(str))
                , _capacity(_size) 
            {
                this->_str = new char[this->_capacity + 1];
                strcpy(this->_str, str);
            }


            void Swap(string& tmp) {
                swap(_str, tmp._str);
                swap(_size, tmp._size);
                swap(_capacity, tmp._capacity);
            }
            //  s2(s1)   现代写法的核心：安排别人干活，窃取劳动成果
            string(const string& src)
                : _str(nullptr)
                , _size(0)
                , _capacity(0)
            {
                string tmp(src._str);
                Swap(tmp);
            }

            string& operator=(string src) {
                Swap(src);
                return *this;
            }



            /* 迭代器 */
            typedef char* iterator;   // 定義普通迭代器
            typedef const char* const_iterator;   // 定義const迭代器      
            iterator begin() {
                return this->_str;  // 返回字符串起始位
            }
            iterator end() {  
                return this->_str + this->_size;  // 返回字符串有效字符的下位
            }
            const_iterator begin() const {
                return this->_str;
            }
            const_iterator end() const {
                return this->_str + this->_size;
            }
            
            /* 返回C格式字符串 */
            const char* c_str() const { 
                return this->_str; 
            };    

            /* 返回字符串大小 */
            size_t size() const { 
                return this->_size; 
            }

            /* 返回字符串容量 */
            size_t capacity() const { 
                return this->_capacity; 
            }

            /* 方括號訪問操作符 */
            char& operator[](size_t pos) {
                assert(pos < this->_size);    // 檢查訪問是否越界
                return this->_str[pos];
            }
            const char& operator[](size_t pos) const {
                assert(pos < this->_size);
                return this->_str[pos];
            }

            /* 擴容 */
            void reserve(size_t new_capacity) {
                if (new_capacity > this->_capacity) {
                    char* tmp = new char[new_capacity + 1];
                    strcpy(tmp, this->_str);
                    delete[] this->_str;

                    this->_str = tmp;
                    _capacity = new_capacity;
                }
            }

            /* 初始化n個字符 */
            string& resize(size_t new_capacity, char fill_val) {
                if (new_capacity <= _size) {
                    _str[_size] = '\0';
                    _size = new_capacity;
                }
                else {
                    if (new_capacity > _capacity) 
                        reserve(new_capacity);
                    for (size_t i = _size; i < new_capacity; i++) 
                        _str[i] = fill_val;

                    _size = new_capacity;
                    _str[_size] = '\0';
                }
            }

            /* 插入 */
            string& insert(size_t pos, char ch) {
                // 檢查越界
                assert(pos <= this->_size);
                // 检查是否需要扩容
                if (this->_size == this->_capacity) {
                    reserve(this->_capacity == 0 ? 4 : this->_capacity * 2);
                }
                // 挪動數據
                size_t end = _size + 1;
                while (end > pos) {
                    this->_str[end] = this->_str[end - 1];
                    end--;
                }
                // 插入數據
                this->_str[pos] = ch;
                this->_size++;

                return *this;
            }
            string& insert(size_t pos, const char* str) {
                // 檢查越界
                assert(pos <= this->_size);
                // 检查是否需要扩容
                size_t len = strlen(str);
                if (this->_size + len > this->_capacity) {
                    reserve(this->_size + len);
                }
                // 往後挪動len個位置
                size_t end = _size + len;
                while (end > pos + len - 1) 
                    _str[end--] = _str[end - len];

                strncpy(_str + pos, str, len);
                _size += len;

                return *this;
            }

            /* 尾插 */
            void push_back(char ch) {
                insert(this->_size, ch);
            }

            /* 字符串追加 */
            void append(const char* str) {
                insert(this->_size, str);
            }

            /* 字符串加等 */
            string& operator+=(char ch) {
                push_back(ch);
            }
            string& operator+=(const char* str) {
                append(str);
            }

            /* 刪除 */
            string& erase(size_t pos, size_t len = npos) {
                // 如果要全部刪完
                if (len == npos || pos + len >= _size) {
                    _str[pos] = '\0';
                    _size = pos;
                } 
                // 刪一部分
                else {
                    size_t begin = pos + len;
                    while (begin <= _size) {
                        _str[begin - len] = _str[begin];
                        begin++;
                    }
                    _size -= len;
                }
            }

            /* 查找 */
            size_t find(char ch, size_t pos = 0) {
                for (; pos < _size; pos++) {
                    if (_str[pos] == ch) {
                        return pos;
                    }
                }
                return npos;
            }
            size_t find(const char* str, size_t pos = 0) {
                const char* p = strstr(_str + pos, str);
            }


        private:
            char* _str;  
            size_t _size;   // 有效字符個數（不含斜杠零）
            size_t _capacity;  // 實際存儲的有效字符的空間
        public:
            const static size_t npos = -1;
    };

    // const size_t string::npos = -1;


    void test_string1() {
        foxny::string s1("abc");
        foxny::string::iterator it = s1.begin();
        while (it != s1.end()) {
            //*it -= 1;
            cout << *it << " ";
            it++;
        }
        cout << endl;

        for (auto ch : s1) {
            cout << ch << " ";
        }
        cout << endl;
    }
}

int main(void)
{
    foxny::test_string1();

    return 0;
}


