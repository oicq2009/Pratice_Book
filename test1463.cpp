#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
#define MAX 10000
#define __T template<class T>
using namespace std;

namespace NiuNiu {
	template<class T>
	class Stack {
	public:
		Stack();
		Stack(int n);
		int create_stack(int n);
		int is_empty();
		int is_full();
		int push(T x);
		int pop(T& save_data);
		T top();
		~Stack();

		friend int isoperator(char& ch);
		friend int isp(char& e);//返回栈中运算符的优先级
		friend int icp(char& e);//返回栈外运算符的优先级
		friend int compute(int x, char a, int y);//求值函数

	private:
		T* _array;
		int _size;
		int _top;
	};

	/* 默认构造函数 */
	template<typename T>
	Stack<T>::Stack() {
		_top = -1;
	}

	/* 创建长度为n的栈的构造函数 */
	template<class T>
	Stack<T>::Stack(int n) {
		create_stack(n);
	}

	/* 创建长度为n的栈 */
	template<class T>
	int Stack<T>::create_stack(int n) {
		if (n <= 0) {
			return 0;
		}
		_array = new T[n];
		_size = n;
		_top = -1;
	}

	/* 判断栈是否为空 */
	template<class T>
	int Stack<T>::is_empty() {
		return _top == -1;
	}

	/* 判断栈是否为满 */
	template<class T>
	int Stack<T>::is_full() {
		return _top >= _size - 1;
	}

	/* 入栈 */
	template<class T>
	int Stack<T>::push(T x) {
		if (_top >= _size - 1) {   // 判断栈是否为空
			return 0;
		}
		_array[++_top] = x;          // 插入数据

		return 1;
	}

	/* 出栈 */
	template<class T>
	int Stack<T>::pop(T& save_data) {
		if(_top == -1) {
			return 0;
		}
		save_data = _array[_top--];

		return 1;
	}

	/* 返回栈顶元素 */
	template<class T>
	T Stack<T>::top() {
		return _array[_top];
	}

	/* 析构函数 */
	template<class T>
	Stack<T>::~Stack() {
		delete[] _array;
		_array = nullptr;
		_size = _top = 0;
	}



	int isoperator(char& e)        //判断是否为运算符
	{
		if (e == '+' || e == '-' || e == '*' || e == '/' || e == '(' || e == ')' || e == '#' || e == 'P' || e == 'N')
			return 1;      //是运算符返回1
		else
			return 0;      //不是运算符返回0
	}
	int isp(char& e)               //返回栈中运算符的优先级
	{
		switch (e)
		{
		case '#':
			return 0; break;
		case '(':
			return 1; break;
		case '+':
		case '-':
			return 2; break;
		case '*':
		case '/':
			return 3; break;
		case 'P':
		case 'N':
			return 4; break;
		case ')':
			return 5; break;
		default:
			return -1; break;
		}
	}
	int icp(char& e)                 //返回栈外运算符的优先级
	{
		switch (e)
		{
		case '#':
			return 0; break;
		case ')':
			return 1; break;
		case '+':
		case '-':
			return 2; break;
		case '*':
		case '/':
			return 3; break;
		case 'P':
		case 'N':
			return 4; break;
		case '(':
			return 5; break;
		default:
			return -1; break;
		}
	}
	int compute(int x, char a, int y)
	{
		switch (a)
		{
		case '+':                //计算加法
			return x + y; break;
		case '-':                //计算减法
			return x - y; break;
		case '*':                //计算乘法
			return x * y; break;
		case '/':                //计算除法
			return x / y; break;
		default:
			return -1; break;
		}
	}
	int get()
	{
		char a, b, c;
		int i, j, f, value = 0, firstOpnd = 0, secondOpnd=0, m = 0;
		Stack<char> OPTR(MAX);    //建立运算符栈
		Stack<int> OPND(MAX);     //建立操作数栈
		OPTR.push('#');           //'#'压栈
		cout << "请输入中缀表达式： ";
		a = getchar();
		while (a != '#' || OPTR.top() != '#')
		{
			if (!isoperator(a))   //不是运算符，即为操作数，操作数入栈
				OPND.push(a - 48);//将字符型转化为整型数字
			else                  //是运算符，与栈顶运算符比较优先级大小
			{
				b = OPTR.top();//得到栈顶元素
				i = isp(b);       //栈顶运算符的优先级
				j = icp(a);       //栈外运算符的优先级
				if (i < j)        //栈外运算符优先级高，运算符入栈
					OPTR.push(a);
				else
				{
					OPTR.pop(b);
					if (b != '(' && i == j || i > j)
					{
						c = OPTR.top();
						if ((c == '(' || c == '#') && (b == 'P' || b == 'N'))    /*c为一元运
																				算符：正负号*/
						{
							OPND.pop(firstOpnd); //得到操作数
							switch (b)
							{
							case 'P':            //正号
								f = firstOpnd * 1;
								break;
							case 'N':            //负号
								f = firstOpnd * (-1);
								break;
							}
						}
						else                     //c为二元运算符
						{
							OPND.pop(secondOpnd); //得到第二操作数
							OPND.pop(firstOpnd);  //得到第一操作数
							f = compute(firstOpnd, b, secondOpnd); //计算求值
						}
						OPND.push(f);             //求值结果压栈
						continue;
					}
				}
			}
			c = a;
			a = getchar();                         //继续读取字符
			while (!isoperator(a) && !isoperator(c))  /*若连续读取字符均为数字，则乘以位权
													  得到多位数*/
			{
				OPND.pop(m);
				m = m * 10 + a - 48;
				OPND.push(m);
				c = a;
				a = getchar();
			}

		}
		OPND.pop(value);
		return value;      //返回表达式的结果
	}
}


int main()
{
	int a;
	a = NiuNiu::get();
	cout << "运算结果为:  " << a << endl;
	return 0;
}




