#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

namespace fonxy
{
    class string {
        public:
            /* 全缺省建構函式 */
            string(const char* str = "")
                : _size(strlen(str))  // 計算初始值的大小
                , _capacity(_size)    // 開闢對應的容量
            {
                _str = new char[_capacity + 1];  // 多開闢一個記憶體留給斜杠零
                strcpy(_str, str);   // 將傳入的 str 拷貝至成員變數 _str 中
            }

            /* 拷貝建構函式 */
            string(const string& src)  
                : _size(src._size)   // _size設為源的大小
                , _capacity(src._capacity)  // _capacity設為源的容量
            {
                _str = new char[_capacity + 1];  // 開闢一塊能存的下源字符串的空間
                strcpy(_str, src._str);  // 將源字符串拷貝至 _str 中
            }

            /* 賦值重載 */
            string& operator=(const string& src) {
                if (this != &src) {     // 防止自己跟自己賦值
                    char* tmp = new char[src._capacity + 1];   // 臨時開闢到tmp中
                    strcpy(tmp, src._str);      // 將源暫時拷貝到tmp中
                    delete[] _str;              // 刪除當前字符串

                    _str = tmp;                 // 替換成新的字符串 
                    _size = src._size;          // 替換成新的大小
                    _capacity = src._capacity;  // 替換成新的容量
                }

                return *this;   // 返回this指標
            }

            /* 解構式 */
            ~string() {
                delete[] _str;
                _str = nullptr;

                _size = _capacity = 0;
            }

            /* 迭代器 */
            typedef char* iterator;    // string 迭代器就是一個原生指針
            typedef const char* const_iterator;   // 同上
            iterator begin() {
                return _str;
            }
            iterator end() {
                return _str + _size;
            }
            const_iterator begin() const {
                return _str;
            }
            const_iterator end() const {
                return _str + _size;
            }

            /* 數據的返回 */
            const char* c_str() const {
                return _str;               // 返回C格式的字符串
            }
            size_t size() const {
                return _size;              // 返回字符串大小
            }
            size_t capacity() const {
                return _capacity;          // 返回字符串容量
            }
            iterator c_str_end() const {
                return _str + _size - 1;   // 返回字符串最後一個有效字符
            }

            /* operator[] 重載 */
            char& operator[](size_t index) {
                assert(index < _size);
                return _str[index];
            }
            const char& operator[](size_t index) const {
                assert(index < _size);
                return _str[index];
            }

            /* 增容 */
            void reserve(size_t new_capacity) {
                if (new_capacity > _capacity) {   // 檢查是否需要增容
                    char* tmp = new char[new_capacity + 1];
                    strcpy(tmp, _str);
                    delete[] _str;

                    _str = tmp;
                    _capacity = new_capacity;
                }
            }

            /* 尾部插入 */
            void push_back(char x) {
                /*
                if (_size == _capacity) {   // 檢查是否需要增容
                    reserve(_capacity == 0 ? 4 : _capacity * 2);  // 首次給4，後期都按原容量的二倍去擴
                }
                _str[_size++] = x;     // 在斜杠零位置插入，插入後 ++_size
                _str[_size] = '\0';    // 手動放置新的斜杠零
                */

               insert(_size, x);
            }
            void append(const char* s) {
                /*
                size_t len = strlen(s);          // 計算插入的字符串的大小
                if (_size + len > _capacity) {   // 檢查是否需要擴容
                    reserve(_size + len);        // 擴的大小夠用就行
                }
                strcpy(_str + _size, s);         // 將插入的字符串拷貝到斜杠零位置
                _size += len;                    // 更新字符串大小
                */

                insert(_size, s);
            }
            string& operator+=(char x) {
                push_back(x);
                return *this;
            }
            string& operator+=(const char* s) {
                append(s);
                return *this;
            }

            /* 任意位置插入 */
            string& insert(size_t pos, char x) {
                assert(pos <= _size);      // 防止下標越界

                if (_size == _capacity) {    // 檢查是否需要增容
                    reserve(_capacity == 0 ? 4 : 2 * _capacity);
                }

                size_t end = _size + 1;             // 創建移動標誌
                while ( end > _size ) {             // 向後挪動數據當直到end==_size時無需再挪
                    _str[end] = _str[end - 1];      // 向後移動
                    end--;
                }

                _str[pos] = x;    // 插入數據
                _size++;          // 字符串大小+1

                return *this;
            }
            string& insert(size_t pos, const char* s) {
                assert(pos <= _size);

                size_t len = strlen(s);
                if (_size + len > _capacity) {
                    reserve(_size + len);
                }

                size_t end = _size + len;
                while (end > pos + len - 1) {
                    _str[end] = _str[end - len];
                    end--;
                }
                strncpy(_str + pos, s, len);
                _size += len;

                return *this;
            }

            /* 擴容：resize */
            void resize(size_t new_capacity, char init_ch = '\0') {
                if (new_capacity <= _size) {      // 若開闢的容量比_size小
                    _str[new_capacity] = '\0';    // 手動添加斜杠零截斷
                    _size = new_capacity;         // 更新大小
                }
                else {    // 若開的容量比 _size 大
                    if (new_capacity > _capacity) {
                        reserve(new_capacity);
                    }
                    memset(_str + _size, init_ch, new_capacity - _size);
                    _size = _capacity;
                    _str[_size] = '\0';
                }
            }

            /* 查找 */
            size_t find(char key) {
                for (size_t i = 0; i < _size; i++)
                    if (key == _str[i])
                        return i;
                return npos;
            }
            size_t find(const char* substr, size_t pos = 0) {
                const char* ptr = strstr(_str + pos, substr);
                if (ptr == nullptr)
                    return npos;
                else
                    return ptr - _str;   // 找到了，返回子串首次出现的地址
            }

            /* 刪除 */
            string& erase(size_t pos, size_t len = npos) {
                assert(pos < _size);   // _size位置處為斜杠零，所以必須控制為小於

                if (len == pos || pos + len >= _size) {
                    _str[pos] = '\0';
                    _size = pos;
                }
                else {
                    strcpy(_str + pos, _str + pos + len);
                    _size -= len;
                }

                return *this;
            }

        private:
            char* _str;
            size_t _capacity;
            size_t _size;
        public:
            static const size_t npos = -1;   // 無符號的-1即整型的最大值
    };

    /* 運算符重載 */
    bool operator<(const string& s1, const string& s2) {
        /*
        size_t i1 = 0, i2 = 0;
        while (i1 < s1.size() && i2 < s2.size()) {
            if (s1[i1] < s2[i2]) {
                return true;
            } else if (s1[i1] > s2[i2] {
                return false;
            } else {
                i1++;
                i2++;
            }
        }
        return i2 < s2.size() ? true : false;
        */

        return strcmp(s1.c_str(), s2.c_str()) < 0;
    }
    bool operator==(const string& s1, const string& s2) {
        return strcmp(s1.c_str(), s2.c_str()) == 0;
    }
    bool operator<=(const string& s1, const string& s2) {
        return s1 < s2 || s2 == s2;
    }
    bool operator>(const string& s1, const string& s2) {
        return !(s1 <= s2);
    }
    bool operator>=(const string& s1, const string& s2) {
        return s1 > s2 || s1 == s2;
    }
    bool operator!=(const string& s1, const string& s2) {
        return !(s1 == s2);
    }

    

    /* 測試數據返回接口 */
    void test_string1() {
        string s1("hello");
        cout << s1.c_str() << endl;
        cout << s1.size() << endl;
        cout << s1.capacity() << endl;
        cout << s1.c_str_end() << endl;
    }

    /* 測試迭代器 */
    void test_string2() {
        string s1("hello world");
        // 法1：使用迭代器遍歷訪問
        string::iterator it = s1.begin();
        while (it != s1.end()) {
            cout << *it;
            it++;
        }
        cout << endl;

        // 法2：使用for循環
        for (size_t i = 0; i < s1.size(); i++) {
            cout << s1[i];
        }
        cout << endl;

        // 法3：使用範圍for（語法糖）
        for (auto e : s1) {
            cout << e;
        }
        cout << endl;
    }

    /* 測試尾插 */
    void test_string3() {
        string s("hello world!");
        for (auto e : s) cout << e; cout << endl;

        s.push_back('-');
        for (auto e : s) cout << e; cout << endl;
        
        s.append("nice to meet you!");
        for (auto e : s) cout << e; cout << endl;

        s += 'A';
        for (auto e : s) cout << e; cout << endl;

        s += "HENJFBEFEHIL";
        for (auto e : s) cout << e; cout << endl;
    }

    /* 測試insert*/
    void test_string4() {
		string s1("hello world");
		cout << s1.c_str() << endl;
 
		s1.insert(0, 'X');
		cout << s1.c_str() << endl;
 
		s1.insert(0, "hahahaha");
		cout << s1.c_str() << endl;
	}

    /* 測試刪除 */
    void test_string7() {
		string s1("hello world");
		cout << s1.c_str() << endl;
 
		s1.erase(5, 2);   // 从第五个位置开始，删两个字符
		cout << s1.c_str() << endl;
 
		s1.erase(5, 20);  // 从第五个位置开始，删完
		cout << s1.c_str() << endl;
 
	}

    
}


int main(void) {
    fonxy::test_string1();

    return 0;
}

