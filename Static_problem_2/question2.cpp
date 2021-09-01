#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Board {
public:
	static string x[100];
	static int top;
	static void add(string str);
	static void print();
};

int Board::top = {};
string Board::x[] = {};

void Board::add(string str) {
	x[top++] = str;
}

void Board::print() {
	cout << "************* �Խ��� �Դϴ�. *************\n";
	for (int i = 0; i < top; i++) {
		cout << i << ": " << x[i] << '\n';
	}
}

int main() {
	memset(Board::x, 0, sizeof(string) * 100);
	Board::add("�߰����� ���� ���� ���� �����Դϴ�.");
	Board::add("�ڵ� ����� ���� �̿��� �ּ���.");
	Board::print();
	Board::add("���Ҹ� �л��� ������ȸ �Ի��Ͽ����ϴ�. �������ּ���");
	Board::print();
}