#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	vector<string> name_list{ "����","�ٳ���","���" };
	auto it = find(name_list.begin(), name_list.end(), "����");
	if (it != name_list.end()) cout << "�־��\n";
	else cout << "�����\n";
	return 0;
}