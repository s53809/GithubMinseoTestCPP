#include <iostream>
using namespace std;

class Person {
public:
	int money = 0;
	static int sharedMoney;
	void addMoney(int x);
	void addShared(int x);
};

int Person::sharedMoney = 0;

void Person::addMoney(int x) {
	money += x;
}

void Person::addShared(int x) {
	sharedMoney += x;
}

int main() {
	Person han;
	han.money = 100;
	han.sharedMoney = 200;

	Person lee;
	lee.money = 150;
	lee.addMoney(200);
	lee.addShared(200);

	cout << han.money << ' ' << lee.money << '\n';
	cout << han.sharedMoney << ' ' << lee.sharedMoney << '\n';
}