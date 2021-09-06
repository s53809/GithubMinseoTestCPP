#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> x;
	x.resize(3);
	for (int i = 0; i < 3; i++) {
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	cout << x[1];
}