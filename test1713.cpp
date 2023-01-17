#include <iostream>
using namespace std;

class Date {
public:
	Date(int year = 1, int month = 1, int day = 1);    // 全缺省构造
	int GetMonthDay(int year, int month) const;       // 获取某年某月对应的天数
	void Print() const;                                // 打印函数

	bool operator>(const Date& d) const;               // d1 > d2
	bool operator==(const Date& d) const;              // d1 == d2 
	bool operator>=(const Date& d) const;          // d1 >= d2
	bool operator<(const Date& d) const;           // d1 < d2
	bool operator<=(const Date& d) const;          // d1 <= d2
	bool operator!=(const Date& d) const;          // d1 != d2

	Date& operator+=(int day);				           // d1 += 100
	Date& operator-=(int day);				           // d1 -= 100
	Date operator+(int day) const;                 // d1 + 100
	Date operator-(int day) const;			       // d1 - 100

	Date& operator++();				                   // ++d1;
	Date operator++(int);				               // d1++;
	Date& operator--();                                // --d1;
	Date operator--(int);                              // d1--;

	int operator-(const Date& d) const;                // 日期减日期
	void PrintWeekDay() const;                         // 返回星期几

private:
	int _year;
	int _month;
	int _day;
};

/* 获取月对应的天数 */
int Date::GetMonthDay(int year, int month) const {
	static int monthDatArray[13] = { 0,
		31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31
	};                                          // 简陋哈希
	int day = monthDatArray[month];	            // 获取天数

	if (month == 2                              // 先判断是否为二月
		&& ((year % 4 == 0 && year % 100 != 0)  // 是二月，再判断是否是闰年
			|| (year % 400 == 0))) {
		day += 1;                               // 是闰年，天数+1
	}

	return day;
}

/* 全缺省构造函数 */
Date::Date(int year, int month, int day) {
	this->_year = year;
	this->_month = month;
	this->_day = day;

	// 判断日期是否合法
	if (!(_year >= 0
		&& (month > 0 && month < 13)
		&& (day > 0 && _day <= GetMonthDay(year, month)))) {
		cout << "非法日期: ";
		this->Print();  // 访问成员函数（this可省略）
	}
}

/* 打印函数 */
void Date::Print() const {
	printf("%d-%d-%d\n", this->_year, this->_month, this->_day);
}


/* d1 > d2 */
bool Date::operator>(const Date& d) const {
	if (this->_year > d._year) {
		return true;
	}
	else if (this->_year == d._year
		&& this->_month > d._month) {
		return true;
	}
	else if (this->_year == d._year
		&& this->_month == d._month
		&& this->_day > d._day) {
		return true;
	}
	else {
		return false;
	}
}

/* d1 == d2 */
bool Date::operator==(const Date& d) const {
	return this->_year == d._year
		&& this->_month == d._month
		&& this->_day == d._day;
}

/* d1 >= d2 */
bool Date::operator>=(const Date& d) const {
	return *this > d || *this == d;
}

/* d1 < d2 */
bool Date::operator<(const Date& d) const {
	return !(*this >= d);
}

/* d1 <= d2 */
bool Date::operator<=(const Date& d) const {
	return !(*this > d);
}

/* d1 != d2*/
bool Date::operator!=(const Date& d) const {
	return !(*this == d);
}


/* d1 += 100 */
Date& Date::operator+=(int day) {
	if (day < 0) {
		return *this -= -day;
	}

	this->_day += day;  // 把要加的天数倒进d1里
	while (this->_day > GetMonthDay(this->_year, this->_month)) {   // 判断天数是否需要进位
		this->_day -= GetMonthDay(this->_year, this->_month);   // 减去当前月的天数
		this->_month++;  // 月份+1

		if (this->_month == 13) {   // 判断月份是否需要进位
			this->_month = 1;  // 重置月份
			this->_year++;   // 年份+1
		}
	}

	return *this;
}

/* d1 -= 100 */
Date& Date::operator-=(int day) {
	if (day < 0) {
		return *this += -day;
	}

	this->_day -= day;
	while (this->_day <= 0) {   // 天数为0或小于0了，就得借位，直到>0为止。
		this->_month--;  // 向月借
		if (this->_month == 0) {   // 判断月是否有得借
			this->_year--;   // 月没得借了，向年借
			this->_month = 12;  // 年-1了，月份置为12月
		}

		this->_day += GetMonthDay(this->_year, this->_month);  // 把借来的天数加到_day上
	}

	return *this;
}

/* d1 + 100 */
Date Date::operator+(int day) const {
	Date ret(*this);  // 拷贝构造一个d1
	ret += day;       // ret.operator+=(day);

	return ret;   // 出了作用域ret对象就不在了，所以不能用引用返回
}

/* d1 - 100 */
Date Date::operator-(int day) const {
	Date ret(*this);   // 拷贝构造一个d1
	ret -= day;        // ret.operator-=(day);

	return ret;
}


/* ++d1 */
Date& Date::operator++() {
	*this += 1;
	return *this;
}

/* d1++ */
Date Date::operator++(int) {
	Date ret(*this);   // 拷贝构造一个d1
	*this += 1;

	return ret;
}

/* --d1 */
Date& Date::operator--() {
	*this -= 1;
	return *this;
}

/* d1-- */
Date Date::operator--(int) {
	Date ret(*this);   // 拷贝构造一个d1
	*this += 1;

	return ret;
}

/* 日期减日期 */
int Date::operator-(const Date& d) const {
	// 我默认认为第一个大，第二个小
	Date max = *this;
	Date min = d;
	int flag = 1;      // 立个flag

	// 如果第一个小，第二个大
	if (*this < d) {
		max = d;
		min = *this;
		flag = -1;     // 说明我们立的flag立错了，改成-1
	}

	int count = 0;
	while (min != max) {
		min++;
		count++;
	}

	return count * flag;
}

/* 返回星期几 */
void Date::PrintWeekDay() const {
	// 1900.1.1 日开始算
	const char* week[] = { "周一", "周二", "周三", "周四", "周五", "周六", "周日" };

	int count = *this - Date(1900, 1, 1);  // 可以使用匿名对象
	cout << week[count % 7] << endl;
}





/* 判断左数是否比小于右数 */
template<class T>
bool Less(T left, T right) {
    return left < right;
}

// 特化
template<>
bool Less<Date*>(Date* left, Date* right) {
    return *left < *right;
}

// 函数解决
bool Less(Date* left, Date* right) {
    return *left < *right;
}


int main(void)
{
    cout << Less(1, 2) << endl;        // 可以比较，结果正确

    Date d1(2022, 7, 7);
    Date d2(2022, 7, 8);
    cout << Less(d1, d2) << endl;      // 可以比较，结果正确

    Date* p1 = new Date(2022, 7, 16);
    Date* p2 = new Date(2022, 7, 15);
    cout << Less(p1, p2) << endl;      // 可以比较，结果正确

    return 0;
}




