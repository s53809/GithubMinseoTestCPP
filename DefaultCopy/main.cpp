#include <iostream>
using namespace std;

class DemoClass {
public:
	int *num;
	DemoClass(int num) {
		this->num = new int(num);
	}
	DemoClass(const DemoClass& dc) {
		this->num = new int(*dc.num);
	}
	~DemoClass() {
		delete num;
	}
	void View() {
		cout << "¹øÈ£ : " << *num << '\n';
	}
};

int main() {
	DemoClass dc1(3);
	DemoClass dc2(dc1);
	dc1.View();
	dc2.View();
	return 0;
}