#include <iostream>
using namespace std;

class Foo {
public:
	int m_foo;
	explicit Foo(int foo) : m_foo(foo) {}
	/*~Foo() {
		cout << "¼Ò¸ê" << m_foo << '\n';
	}*/
};

void print_foo(Foo foo) {
	cout << foo.m_foo << '\n';
}

int main() {
	int num = 43;
	print_foo(Foo(num));
	int n = 100;
	double average = 0.0;
	average = (double)n / 3;
	cout << average << '\n';
}