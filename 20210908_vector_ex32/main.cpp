#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <vector>
using namespace std;

class Circle {
public:
	int x, y;
	int radius;
	Circle() : x{ 0 }, y{ 0 }, radius{ 0 }{};
	Circle(int x, int y, int radius) : x{ x }, y{ y }, radius{ radius }{};
	void print() {
		cout << "¹ÝÁö¸§: " << radius << " @(" << x << ", " << y << ")\n";
	}
	void draw() {
		int r = radius / 2;
		HDC hdc = GetWindowDC(GetForegroundWindow());
		Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
	}
};

int main() {
	vector<Circle> objArray;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		Circle obj{ rand() % 300, rand() % 300, rand() % 100 };
		objArray.push_back(obj);
	}
	for (Circle c : objArray) {
		c.print();
	}
	return 0;
}