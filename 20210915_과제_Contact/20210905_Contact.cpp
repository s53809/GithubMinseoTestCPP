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
		cout << "��ȭ��ȣ : " << phoneNumber << "\n�ּ� : " << address << '\n';
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
		cout << "�߰�(1) / Ž��(2) / exit(-1) : ";
		int N;
		cin >> N;
		if (N == -1) {
			cout << "���α׷��� �����մϴ�.";
			break;
		}
		else if (N == 1) {
			cout << "�̸��� �Է��Ͻÿ� : ";
			getchar();
			cin >> nameBox;
			cout << "��ȭ��ȣ�� �Է��Ͻÿ� : ";
			getchar();
			cin >> numBox;
			cout << "�ּҸ� �Է��Ͻÿ� : ";
			getchar();
			getline(cin, addBox);
			playerInfo a(nameBox, numBox, addBox);
			x.push_back(a);
		}
		else if (N == 2) {
			cout << "Ž���ϰ� ���� �̸��� �Է��Ͻÿ� : ";
			cin >> nameBox;
			if (nameBox == "Minsoda") {
				while (true) {
					cout << "ERROR : �߸��� ����.\t";
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
				cout << "������ ã�� ���Ͽ����ϴ�.\n";
			}
			isFind = false;
		}
		else {
			cout << "�ùٸ� ���ڸ� �Է����ּ���.\n";
		}
	}
}