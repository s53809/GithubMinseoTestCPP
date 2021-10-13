#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cout << "문자열의 개수 : ";
	cin >> N;
	vector<string> x;
	x.resize(N);
	for (int i = 0; i < N; i++) {
		cout << "문자열을 입력하시오 : ";
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	for (int i = 0; i < x.size(); i++) {
		cout << x[i] << '\n';
	}
}