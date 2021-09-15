#include <iostream>
#include <string>
#include <vector>
using namespace std;

class playerInfo {
private:
	string name;
	string phoneNumber;
	string address;
public:
	playerInfo(string name, string phoneNumber, string address) {
		this->name = name;
		this->phoneNumber = phoneNumber;
		this->address = address;
	}
	void show() {
		cout << "전화번호 : " << phoneNumber << "\n주소 : " << address << '\n';
	}
	string returnName() {
		return name;
	}
};

int main() {
	vector<playerInfo> x;
	while (true) {
		string nameBox;
		string numBox;
		string addBox;
		cout << "추가(1) / 탐색(2) / exit(-1) : ";
		int N;
		cin >> N;
		if (N == -1) {
			cout << "프로그램을 종료합니다.";
			break;
		}
		else if (N == 1) {
			cout << "이름을 입력하시오 : ";
			getchar();
			cin >> nameBox;
			cout << "전화번호를 입력하시오 : ";
			getchar();
			cin >> numBox;
			cout << "주소를 입력하시오 : ";
			getchar();
			getline(cin, addBox);
			playerInfo a(nameBox, numBox, addBox);
			x.push_back(a);
		}
		else if (N == 2) {
			cout << "탐색하고 싶은 이름을 입력하시오 : ";
			cin >> nameBox;
			if (nameBox == "Minsoda") {
				while (true) {
					cout << "ERROR : 잘못된 접근.\t";
				}
			}
			bool isFind = false;
			for (int i = 0; i < x.size(); i++) {
				if (nameBox == x[i].returnName()) {
					x[i].show();
					isFind = true;
				}
			}
			if (isFind == false) {
				cout << "정보를 찾지 못하였습니다.\n";
			}
			isFind = false;
		}
		else {
			cout << "올바른 숫자를 입력해주세요.\n";
		}
	}
}