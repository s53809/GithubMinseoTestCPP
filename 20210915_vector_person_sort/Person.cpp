#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

Person::Person() {
	this->name = "NULL";
	this->id = "NULL";
	int age = 0;
	int gender = 0;
	int height = 0;
}
Person::Person(const string& name, const string& id, unsigned int age, unsigned int gender, unsigned int height) {
	this->name = name;
	this->id = id;
	this->age = age;
	this->gender = gender;
	this->height = height;
}
string Person::GetName() {
	return name;
}
int Person::GetAge() {
	return age;
}
void Person::ShowInfo() {
	cout << "이름 : " << name << ", 주민번호 : " << id << ", 나이 : " << age << '\n';
}