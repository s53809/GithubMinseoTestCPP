#include <iostream>
#include <string>
using namespace std;

class Time {
private:
	int hour, min, sec;
public:
	Time(int h = 0, int m = 0, int s = 0) :hour(h), min(m), sec(s) { }
	bool operator==(const Time& v2) {
		return (this->hour == v2.hour && this->min == v2.min && this->sec == v2.sec);
	}
	bool operator!=(const Time& v2) {
		return !(*this == v2);
	}
};

int main() {
	Time t1(1, 2, 3), t2(1, 2, 3);
	cout.setf(cout.boolalpha);
	cout << (t1 == t2) << '\n';
	cout << (t1 != t2) << '\n';
	return 0;
}