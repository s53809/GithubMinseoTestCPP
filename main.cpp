#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cout << "���ڿ��� ���� : ";
	cin >> N;
	vector<string> x;
	x.resize(N);
	for (int i = 0; i < N; i++) {
		cout << "���ڿ��� �Է��Ͻÿ� : ";
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	for (int i = 0; i < x.size(); i++) {
		cout << x[i] << '\n';
	}
}