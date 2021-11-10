#include <iostream>
#include <algorithm>
#include <vector>
#include "Person.h"
using namespace std;

bool compare(Person& p, Person& q) {
	return p.GetAge() > q.GetAge();
}

int main() {
	vector<Person> list;
	Person a("������", "1234561234567", 75, 1, 160);
	Person b("�̼���", "1234561234567", 55, 1, 170);
	Person c("ȫ�浿", "1234561234567", 65, 1, 180);
	list.push_back(a);
	list.push_back(b);
	list.push_back(c);
	cout << "���� ��\n";
	for (int i = 0; i < list.size(); i++) {
		list[i].ShowInfo();
	}
	sort(list.begin(), list.end(), compare);
	cout << "���� ��\n";
	for (int i = 0; i < list.size(); i++) {
		list[i].ShowInfo();
	}
	Person fP("������", "1234561234567", 75, 1, 160);
	auto it = find(list.begin(), list.end(), fP);
	if (it != list.end()) {
		cout << "Found\n";
	}
	else {
		cout << "Not Found\n";
	}
}