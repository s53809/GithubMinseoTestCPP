#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	cout << "현재의 v = ";
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		cout << v[i] << ' ';
	}
	cout << "\n삭제 요소 = ";
	while (!v.empty()) {
		cout << v.back() << ' ';
		v.pop_back();
	}
}