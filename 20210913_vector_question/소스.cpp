#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v;
	int count = 0, user_inp = 0;
	cout << "정수의 갯수 : ";
	cin >> count;
	for (int i = 0; i < count; i++) {
		cout << "정수를 입력하세요. : ";
		cin >> user_inp;
		v.push_back(user_inp);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	sort(v.begin(), v.end());
	cout << "최대값 : " << v[v.size() - 1] << '\n' << "최소값 : " << v[0];
}