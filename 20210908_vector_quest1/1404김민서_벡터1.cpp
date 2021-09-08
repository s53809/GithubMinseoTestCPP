#include <iostream>
#include <vector>
using namespace std;
int main() {
	vector<int> x;
	int sum = 0;
	while (true) {
		int box;
		cin >> box;
		if (box == -1) {
			break;
		}
		x.push_back(box);
		sum += x.back();
	}
	cout << sum / x.size() << '\n';
}