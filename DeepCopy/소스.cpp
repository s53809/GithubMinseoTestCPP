#include <iostream>
#include <string>
using namespace std;

class Person {
	char* name;
	char* phone;
	int age;
public:
	Person(char* _name, char* _phone, int _age);
	Person(const Person& dc);
	~Person();
	void ShowData();
};	

Person::Person(char* _name, char* _phone, int _age) {
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	phone = new char[strlen(_phone) + 1];
	strcpy(phone, _phone);
	age = _age;
}

Person::Person(const Person& dc) {
	name = new char[strlen(dc.name) + 1];
	strcpy(name, dc.name);
	phone = new char[strlen(dc.phone) + 1];
	strcpy(phone, dc.phone);
	age = dc.age;
}

Person::~Person() {
	delete[]name;
	delete[]phone;
}

void Person::ShowData() {
	cout << "name: " << name << '\n';
	cout << "phone: " << phone << '\n';
	cout << "age: " << age << '\n';
}

int main() {
	Person p1("KIM", "013-333-5555", 22);
	Person p2(p1);
	p1.ShowData();
	p2.ShowData();
	return 0;
}