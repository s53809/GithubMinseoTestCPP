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
	cout << "************* 게시판 입니다. *************\n";
	for (int i = 0; i < top; i++) {
		cout << i << ": " << x[i] << '\n';
	}
}

int main() {
	memset(Board::x, 0, sizeof(string) * 100);
	Board::add("중간고사는 감독 없는 자율 시험입니다.");
	Board::add("코딩 라운지 많이 이용해 주세요.");
	Board::print();
	Board::add("진소린 학생이 경진대회 입상하였습니다. 축하해주세요");
	Board::print();
}