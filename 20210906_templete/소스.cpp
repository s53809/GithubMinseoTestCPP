#include <iostream>
#include <string>
using namespace std;

template <typename T>
T sum(T a, T b) {
	return a + b;
}

int main() {
	int a = 10, b = 20;
	double d1 = 3.2;
	double d2 = 4.5;
	string str1 = "Hello, ";
	string str2 = "World!";
	cout << sum(a, b) << '\n';
	cout << sum(d1, d2) << '\n';
	cout << sum(str1, str2) << '\n';
}