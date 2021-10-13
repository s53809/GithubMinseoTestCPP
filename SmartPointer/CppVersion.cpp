#include <iostream>
#include <memory>
using namespace std;

class Test {
public:
	Test(int x):x(x) {
		cout << GetX() << " ������" << '\n';
	}
	~Test() {
		cout << GetX() << " �Ҹ���" << '\n';
	}
	int GetX() const { return x; }
private:
	int x;
};

int main() {
	cout << "���� ����\n";
	unique_ptr<Test> p(new Test(1));
	cout << p->GetX() << '\n';
	p.reset(new Test(6));
	cout << p->GetX() << '\n';
	unique_ptr<Test> b(p.release());
	unique_ptr<int[]> ptr(new int[10]);
	for (int i = 0; i < 10; i++) {
		ptr[i] = i + 1;
	}
	for (int i = 0; i < 10; i++) {
		cout << ptr[i] << ' ';	
	}
	cout << '\n';
	cout << "���� ����\n";
	return 0;
}