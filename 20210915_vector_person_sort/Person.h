#pragma once
#include <string>
using namespace std;

class Person {
private:
	string name;
	string id;
	int age;
	int gender;
	int height;
public:
	Person();
	Person(const string& name, const string& id, unsigned int age, unsigned int gender, unsigned int height);
	~Person() { }
	string GetName();
	int GetAge();
	void ShowInfo();
};