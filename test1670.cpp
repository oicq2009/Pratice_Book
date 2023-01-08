#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

namespace chaos {

    class string {
    public:
        /* 全缺省构造函数 */
        string(const char* str = "")
            : _size(strlen(str))
            , _capacity(_size)
        {
            _str = new char[_capacity + 1];
            strcpy(_str, str);
        }

        /* 拷贝构造函数 s2(s1) */
        // string(const string& src)
        //     : _size(src._size)
        //     , _capacity(src._capacity)
        // {
        //     _str = new char[_capacity + 1];
        //     strcpy(_str, src._str);
        // }


            void Swap(string& s) {
                swap(_str, s._str);
                swap(_size, s._size);
                swap(_capacity, s._capacity);
            }
        string(const string& src) 
            : _str(nullptr)
            , _size(0)
            , _capacity(0)
        {
            string tmp(src._str);
            Swap(tmp);
        }
        
        /* 赋值重载 s1 = s3 */
        // string& operator=(const string& src) {
        //     if (this != &src) {
        //         char* tmp = new char[src._capacity + 1];
        //         strcpy(tmp, src._str);
        //         delete[] _str;

        //         _str = tmp;
        //         _size = src._size;
        //         _capacity = src._capacity;
        //     }

        //     return *this;
        // }
        string& operator=(string src) {
            Swap(src);
            return *this;
        }

        /* 迭代器 */
        typedef char* iterator;
        typedef const char* const_iterator;
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

        /* 返回C语言格式字符串 */
        const char* c_str() const {
            return _str;
        }

        /* 返回字符串大小 */
        size_t size() const {
            return _size;
        }

        /* 返回字符串容量 */
        size_t capacity() const {
            return _capacity;
        }

        /* 方块访问符 */
        char& operator[](size_t idx) {
            assert(idx < _size);
            return _str[idx];
        }
        const char& operator[](size_t idx) const {
            assert(idx < _size);
            return _str[idx];
        }

        /* 增容 */
        void reserve(size_t new_capacity) {
            if (new_capacity > _capacity) {
                char* new_str = new char[new_capacity + 1];
                strcpy(new_str, _str);
                delete[] _str;
                _str = new_str;

                _capacity = new_capacity;
            }
        }

        void resize(size_t new_capacity, char init_val = '\0') {
			// 如果预增容量比_size小
            if (new_capacity <= _size) {
				_str[new_capacity] = '\0';
                _size = new_capacity;
			}
            // 如果预增容量比_size大
			else {
                // 检查是否需要扩容
				if (new_capacity > _capacity) {
					reserve(new_capacity);
				}
                // 用初始值填充
				for (size_t i = _size; i < new_capacity; i++) {
					_str[i] = init_val;
				}
				_size = _capacity;
				_str[_size] = '\0';
			}
		}
        
        /* 尾插 */
        void push_back(char ch) {
            // if (_size == _capacity) {
            //     reserve(_capacity == 0 ? 4 : _capacity * 2);
            // }
            // _str[_size++] = ch;
            // _str[_size] = '\0';
            
            insert(_size, ch);
        }

        /* 追加 */
        void append(const char* str) {
            // size_t len = strlen(str);
            // if (_size + len > _capacity) {
            //     reserve(_size + len);
            // }

            // strcpy(_str + _size, str);
            // _size += len;

            insert(_size, str);
        }

        /* 加等 */
        string& operator+=(char ch) {
            push_back(ch);
            return *this;
        }
        string& operator+=(const char* str) {
            append(str);
            return *this;
        }

        /* 插入 */
        string& insert(size_t pos, char ch) {
            assert(pos <= _size);
            // 检查是否需要扩容
            if (_size == _capacity) {
                reserve(_capacity == 0 ? 4 : _capacity * 2);
            }
            // 移动数据
            size_t end = _size + 1;
            while (end > pos) {
                _str[end] = _str[end - 1];
                end--;
            }
            // 插入数据
            _str[pos] = ch;
            _size++;

            return *this;
        }
        string& insert(size_t pos, const char* str) {
            assert(pos <= _size);
            // 检查是否需要扩容
            size_t len = strlen(str);
            if (_size + len > _capacity) {
                reserve(_size + len);
            }
            // 移动数据
            size_t end = _size + len;
            while (end > pos + len - 1) {
                _str[end] = _str[end - len];
                end--;
            }
            // 插入数据
            strncpy(_str + pos, str, len);
            _size += len;
            
            return *this;
        }

        // 查找
        size_t find(char target) {
            for (size_t i = 0; i < _size; i++) {
                if (target == _str[i]) {
                    return i;
                }
            }
            return npos;
        }
        size_t find(const char* str, size_t pos = 0) {
            const char* p = strstr(_str + pos, str);
        }

        // 删除
        string& erase(size_t pos, size_t len = npos) {
            assert(pos < _size);
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

        /* 析构函数 */
        ~string() {
            if (_str) {
                delete[] _str;
                _str = nullptr;
                _size = _capacity = 0;
            }
        }

    private:
        char* _str;
        size_t _size;
        size_t _capacity;
    public:
        static const size_t npos;

    };
    
    /* 初始化npos */
    const size_t string::npos = -1;

    /* 运算符重载 */
    bool operator<(const string& s1, const string& s2) {
        return strcmp(s1.c_str(), s2.c_str()) < 0;
    }
    bool operator==(const string& s1, const string& s2) {
        return strcmp(s1.c_str(), s2.c_str()) == 0;
    }
    bool operator<=(const string& s1, const string& s2) {
        return s1 < s2 || s1 == s2;
    }
    bool operator>(const string& s1, const string& s2) {
        return !(s1 <= s2);
    }
    bool operator>=(const string& s1, const string& s2) {
        return !(s1 < s2);
    }
    bool operator!=(const string& s1, const string& s2) {
        return !(s1 == s2);
    }

    // cout << s1  →  operator<<(cout, s1)
    ostream& operator<<(ostream& out, const string& s) {
        //for (auto ch : s) {
        //	out << ch;
        //}
    
        for (size_t i = 0; i < s.size(); i++) {
            out << s[i];
        }
    
        return out;
    }

    // cin >>
    istream& operator<<(istream& in, string& s) {
        char ch = in.get();
        while (ch == '\n') {
            s += ch;
            ch = in.get();
        }
    
        return in;
    }




	/* 测试用 */
	void test_string1() {
		string s1("hello world");
		string s2(s1);
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
 
		string s3("pig");
		cout << s3.c_str() << endl;
 
		s1 = s3;
		cout << s1.c_str() << endl;
	}
 
	void test_string2() {
		string s1("hello world");
		string s2;
 
		for (size_t i = 0; i < s1.size(); i++) {
			cout << s1[i] << " ";
		}
		cout << endl;
	}
 
	void test_string3() {
		string s1("hello world");
		string s2;
 
		s1[0] = 'F';
		for (size_t i = 0; i < s1.size(); i++) {
			cout << s1[i] << " ";
		}
		cout << endl;
	}
 
	void test_string4() {
		string s1("hello world");
 
		// 迭代器写
		string::iterator it = s1.begin();
		while (it != s1.end()) {
			*it += 1;
			it++;
		}
 
		// 迭代器读
		it = s1.begin();   // 重置起点
		while (it != s1.end()) {
			cout << *it << " ";
			it++;
		}
	}
 
	void test_string5() {
		string s1("hello world");
		cout << s1.c_str() << endl;
 
		s1.push_back('!');
		cout << s1.c_str() << endl;
 
		s1.push_back('A');
		cout << s1.c_str() << endl;
	}
 
	void test_string6() {
		string s1("hello world");
		cout << s1.c_str() << endl;
 
		s1 += '!';
		cout << s1.c_str() << endl;
 
		s1 += "this is new data";
		cout << s1.c_str() << endl;
	}
 
	void test_string7() {
		string s1("hello world");
		cout << s1.c_str() << endl;
 
		s1.insert(0, 'X');
		cout << s1.c_str() << endl;
 
		s1.insert(0, "hahahaha");
		cout << s1.c_str() << endl;
	}
 
	void test_string8() {
		string s1("hello world");
		cout << s1.c_str() << endl;
 
		s1.erase(5, 2);   // 从第五个位置开始，删两个字符
		cout << s1.c_str() << endl;
 
		s1.erase(5, 20);  // 从第五个位置开始，删完
		cout << s1.c_str() << endl;
 
	}
}

int main(void) {
    chaos::test_string6();

    return 0;
}

