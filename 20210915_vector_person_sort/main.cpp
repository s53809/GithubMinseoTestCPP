#include <iostream>
#include <vector>
#include <string>
#include "Person.h"

int main() {
	vector<Person> list;
	list.push_back(Person("������", "1234561234567", 75, 1, 160));
	list.push_back(Person("�̼���", "1234561234567", 65, 1, 170));
	list.push_back(Person("ȫ�浿", "1234561234567", 55, 1, 180));

	for (int i = 0; i < list.size(); i++) {
		list[i].ShowInfo();
	}
	return 0;
}