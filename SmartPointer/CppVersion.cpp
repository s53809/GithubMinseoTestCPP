#include <iostream>
#include <memory>
using namespace std;

class Test {
public:
	Test(int x):x(x) {
		cout << GetX() << " 생성자" << '\n';
	}
	~Test() {
		cout << GetX() << " 소멸자" << '\n';
	}
	int GetX() const { return x; }
private:
	int x;
};

int main() {
	cout << "메인 시작\n";
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
	cout << "메인 종료\n";
	return 0;
}