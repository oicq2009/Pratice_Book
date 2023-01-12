#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

namespace foxny {

    class string {
        public:
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

            string(const char* str = "") : _size(strlen(str)), _capacity(_size) {
                _str = new char[_capacity + 1];
                strcpy(_str, str);
            }
            string(const string& src) : _size(src._size), _capacity(src._capacity) {
                _str = new char[_capacity + 1];
                strcpy(_str, src._str);
            }
            string& operator=(const string& src) {
                if (this != &src) {
                    char* tmp = new char[src._capacity + 1];
                    strcpy(tmp, src._str);
                    delete[] _str;
                    _str = tmp;

                    _size = src._size;
                    _capacity = src._capacity;
                }

                return *this;
            }

            const char* c_str() const { 
                return _str;
            }
            size_t size() const { 
                return _size; 
            }

            char& operator[](size_t pos) {
                assert(pos < _size);
                return _str[pos];
            }
            const char& operator[](size_t pos) const {
                assert(pos < _size);
                return _str[pos];
            }

            ~string() {
                delete[] _str;
                _str = nullptr;
                _size = _capacity = 0;
            }

            void reserve(size_t new_capacity) {
                if (new_capacity > _capacity) {
                    char* tmp = new char[new_capacity + 1];
                    strcpy(tmp, _str);
                    delete[] _str;
                    _str = tmp;

                    _capacity = new_capacity;
                }
            }

            void push_back(char x) {
                if (_size == _capacity) {
                    reserve(_capacity == 0 ? 4 : _capacity * 2);
                }

                _str[_size] = x;
                _size++;
                _str[_size] = '\0';
            }

            void append(const char* str) {
                size_t len = strlen(str);
                if (_size + len > _capacity) {
                    reserve(_size + len);
                }

                strcpy(_str + _size, str);
                _size += len;
            }

            string& operator+=(char x) {
                push_back(x);
                return *this;
            }
            string& operator+=(const char* str) {
                append(str);
                return *this;
            }

            string& insert(size_t idx, char x) {
                assert(idx <= _size);
                if (_size == _capacity) {
                    reserve(_capacity == 0 ? 4 : _capacity * 2);
                }

                size_t end = _size + 1;
                while (end > idx) {
                    _str[end] = _str[end - 1];
                    end--;
                }
                _str[idx] = x;
                _size++;

                return *this;      
            }

            string& insert(size_t idx, const char* str) {
                assert(idx <= _size);
                size_t len = strlen(str);
                if (_size + len > _capacity) {
                    reserve(_size + len);
                }

                size_t end = _size + len;
                while (end > idx) {
                    _str[end] = _str[end - 1];
                    end--;
                }
                strncpy(_str + len, len, str);
                _str += len;
            }

        private:
            char* _str;
            size_t _size;
            size_t _capacity;
    };

    void test_string5() {
		string s1("hello world");
		cout << s1.c_str() << endl;
 
		s1 += '!';
		cout << s1.c_str() << endl;
 
		s1 += "this is new data";
		cout << s1.c_str() << endl;
	}
}

int main(void)
{
    foxny::test_string5();

    return 0;
}


