#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<string> name_list{ "딸기","바나나","사과" };
	auto it = find(name_list.begin(), name_list.end(), "딸기");
	if (it != name_list.end()) cout << "있어용\n";
	else cout << "없어용\n";
	return 0;
}