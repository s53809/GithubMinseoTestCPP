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
	double d2 = 5.5;
	string str1 = "Hello, ";
	string str2 = "World!";
	cout << "int ��:" << sum<int>(a, b) << '\n';
	cout << "double ��:" << sum<double>(d1, d2) << '\n';
	cout << "string ��:" << sum<string>(str1, str2) << '\n';
}