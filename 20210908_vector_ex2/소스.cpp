#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	cout << "������ v = ";
	for (auto& e : v) {
		cout << e << ' ';
	}
	cout << "\n���� ��� = ";
	while (!v.empty()) {
		cout << v.back() << ' ';
		v.pop_back();
	}
	cout << '\n';
}