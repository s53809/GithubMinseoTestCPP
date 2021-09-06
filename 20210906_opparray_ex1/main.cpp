#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
using namespace std;

class Circle {
public:
	int x, y;
	int radius;
	Circle() : x{ 0 }, y{ 0 }, radius{ 0 }{};
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
	srand(time(NULL));
	Circle objArray[10];
	char ah;
	while (true) {
		ah = getchar();
		getchar();
		if (ah == 'q') {
			break;
		}
		if (ah != 'c') {
			cout << "ERROR";
			break;
		}
		for (Circle& c : objArray) {
			c.x = rand() % 500;
			c.y = rand() % 300;
			c.radius = rand() % 100;
		}
		for (Circle c : objArray) {
			c.draw();
		}
	}
	return 0;
}