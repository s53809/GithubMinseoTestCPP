#include <iostream>
#include <string>
#include "Person.h"

Person::Person() :name(""), id(""), age(0), gender(0), height(0) {}
Person::Person(const string& name, const string& id, unsigned int age, unsigned int gender, unsigned int height) {
	this->name = name;
	this->id = id;
	this->age = age;
	this->gender = gender;
	this->height = height;
}
void Person::ShowInfo() {
	cout << "이름: " << name << ", 주민번호: " << id << ", 나이: " << age << '\n';
}
string Person::GetName() { return name; }
int Person::GetAge() { return age; }
bool Person::operator==(const Person& p) {
	if (this->name == p.name && this->id==p.id&&this->age==p.age&&this->gender==p.gender&&this->height==height) {
		return true;
	}
	return false;
}