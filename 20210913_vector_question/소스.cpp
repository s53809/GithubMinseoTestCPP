#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	int count = 0, user_inp = 0;
	cout << "������ ���� : ";
	cin >> count;
	for (int i = 0; i < count; i++) {
		cout << "������ �Է��ϼ���. : ";
		cin >> user_inp;
		v.push_back(user_inp);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	sort(v.begin(), v.end());
	cout << "�ִ밪 : " << v[v.size() - 1] << '\n' << "�ּҰ� : " << v[0];
}