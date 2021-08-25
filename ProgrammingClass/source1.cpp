#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	string name;
	string id; // �ֹ� ��ȣ :
	// 123456 1234567
	unsigned char age; // ����
	unsigned char gender; // ����
	unsigned char height; // Ű
public:
	Person();
	Person(const string& name, const string& id, unsigned char age, unsigned char gender, unsigned char height);
	Person& operator= (const Person& p);
	~Person();
	void ShowInfo();
	static int person_count;
};

int Person::person_count = 0;

Person::Person()
{
	name = "", id = "";
	age = 0; gender = 0; height = 0;
	person_count++;
	cout << "current person count : " << person_count << endl;
}

Person::Person(const string& name, const string& id, unsigned char age, unsigned char gender, unsigned char height)
{
	this->name = name; this->id = id;
	this->age = age; this->gender = gender;
	this->height = height;
	person_count++;
	cout << "current person count : " << person_count << endl;
}
Person& Person::operator=(const Person& p)
{
	name = p.name; id = p.id;
	age = p.age; gender = p.gender;
	height = p.height;
	return *this;
}
Person::~Person()
{
	person_count--;
	cout << "current person count : " << person_count << endl;

}

void Person::ShowInfo()
{
	cout << "�̸� : " << name << ", �ֹι�ȣ : " <<
		id << endl;
}
int main(void)
{
	Person p1 = Person("������",
		"1234561234567", 45, 1, 160);
	Person p2;
	p2 = p1;
	return 0;
}
