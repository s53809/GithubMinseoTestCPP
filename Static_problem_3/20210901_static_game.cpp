#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
using namespace std;

class Game {
private:
	double energy = 100;
	static int life; //static을 활용을 잘 못했습니다 T^T 거의 의미가 없어요
public:
	double Damage(int dam);
	static void Die();
	void lifeRecharge();
	int showEnergy();
};

int Game::life = 1;

void Game::Die() {
	life--;
	cout << "생명이 1 감소하여 " << life << "이 되었습니다." << "\n\n";
}

double Game::Damage(int dam) {
	double damaged = 0;
	if (energy > 0) {
		damaged += dam;
		energy -= damaged;
		cout << "에너지가 " << damaged << " 감소하여 " << energy << " 이 되었습니다.\n";
		if (energy < 0) {
			life--;
			energy = 100;
			cout << "생명이 1 감소하여 " << life << "이 되었습니다." << "\n\n";

		}
	}
	return energy;
}

void Game::lifeRecharge() { // 얘는 안썼습니다
	cout << "라이프를 충전하시겠습니까? (예: 1/아니오: 2)\n";
	int N;
	cin >> N;
	if (N == 1) {
		cout << "결제 수단은 무통장 입금입니다.\n";
	}
}

int Game::showEnergy() {
	return energy;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	srand((unsigned int)time(NULL));
	cout << "죽음의 가위바위보를 시작합니다.\n";
	Sleep(1000);
	cout << "당신의 이름을 알려주세요 >> "; 
	string noMean;
	cin >> noMean;
	cout << "\'시미야 진\' 님.. ";
	Sleep(1000);
	cout << "멋진 이름이군요..\n";
	Sleep(1000);
	cout << "지금 상대를 초청하겠습니다.\n";
	Sleep(5000);
	cout << "\'구스타브\'";
	Sleep(1000);
	cout << " 님이 초대되었습니다.\n";
	Sleep(1000);
	cout << "그럼 부디 이야기꾼의 가호가 있길";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".\n";
	Sleep(1000);
	system("cls");
	cout << "게임을 시작하지!\n";
	string answer;
	string counter;
	string ai_answer;
	string ai_counter;
	Game character;
	Game ai;
	while (true) {
		Sleep(1000);
		cout << "\'시미야 진\'의 턴!\n";
		Sleep(1000);
		cout << "가위, 바위, 보 중에 선택해라 >> ";
		cin >> answer;
		if (answer == "가위") {
			cout << "마법 가위를 선택했다!\n";
		}
		else if (answer == "바위") {
			cout << "힘 바위를 선택했다!\n";
		}
		else if (answer == "보") {
			cout << "보를 선택했다!\n";
			cout << "마법 보자기인가 힘 보자기인가 입력: (마법/힘) >> ";
			cin >> counter;
			if (counter == "마법") {
				cout << "마법 보자기다!\n";
			}
			else if (counter == "힘") {
				cout << "힘 보자기다!\n";
			}
			else {
				cout << "NULL을 선택했다!\n";
				cout << "치명적인 오류 시스템 발견!\n";
				cout << "프로그램을 강제로 종료합니다.\n";
				return 0;
			}
		}
		else if (answer == "총") {
			cout << "총을 선택했다!\n";
		}
		else {
			cout << "NULL을 선택했다!\n";
			cout << "치명적인 오류 시스템 발견!\n";
			cout << "프로그램을 강제로 종료합니다.\n";
			return 0;
		}
		cout << "\'구스타브\'의 턴!!\n";
		cout << "기다리는 중";
		for (int i = 0; i < 3; i++) {
			cout << ". ";
			Sleep(2000);
		}
		int suntack = rand() % 4 + 1;
		switch (suntack) {
		case 1:
			ai_answer = "가위";
			break;
		case 2:
			ai_answer = "바위";
			break;
		case 3:
			ai_answer = "보";
			ai_counter = "마법";
			break;
		case 4:
			ai_answer = "보";
			ai_counter = "힘";
			break;
		default:
			break;
		}
		cout << "판결!\n";
		Sleep(1000);
		cout << "\'시미야 진\'은 ";
		Sleep(1000);
		if (answer == "가위") {
			cout << "마법 가위를 냈다!\n";
			Sleep(1000);
			cout << "상대에게 마법 10의 데미지!\n";
			if (ai_answer == "보") {
				cout << "\'구스타브\'의 카운터!!\n";
				if (ai_counter == "마법") {
					Sleep(1000);
					cout << "성공!\n";
					cout << "\'시미야 진\'은 마법 20 데미지를 받았다!!\n";
					character.Damage(20);
				}
				else {
					cout << "실패!\n";
					cout << "\'구스타브\'는 마법 10 데미지를 받았다!!\n";
					ai.Damage(10);
				}
			}
			else {
				cout << "\'구스타브\'는 마법 10 데미지를 받았다!!\n";
				ai.Damage(10);
			}
		}
		if (answer == "바위") {
			cout << "힘 바위를 냈다!\n";
			Sleep(1000);
			cout << "상대에게 10의 데미지!\n";
			if (ai_answer == "보") {
				cout << "\'구스타브\'의 카운터!!\n";
				if (ai_counter == "힘") {
					Sleep(1000);
					cout << "성공!\n";
					cout << "\'시미야 진\'은 20 데미지를 받았다!!\n";
					character.Damage(20);
				}
				else {
					cout << "실패!\n";
					cout << "\'구스타브\'는 10 데미지를 받았다!!\n";
					ai.Damage(10);
				}
			}
			else {
				cout << "\'구스타브\'는 10 데미지를 받았다!!\n";
				ai.Damage(10);
			}
		}
		else if (answer == "총") {
			cout << " \'구스타브\' 에게 총을 쐈다\n";
			Sleep(1000);
			cout << "효과는 굉장했다! 상대는 100의 피해를 입었다!\n";
			ai.Damage(100);
		}
		Sleep(1000);
		cout << "\'구스타브\'은 ";
		Sleep(1000);
		if (ai_answer == "가위") {
			cout << "마법 가위를 냈다!\n";
			Sleep(1000);
			cout << "상대에게 마법 10의 데미지!\n";
			if (answer == "보") {
				cout << "\'시미야 진\'의 카운터!!\n";
				if (counter == "마법") {
					Sleep(1000);
					cout << "성공!\n";
					cout << "\'구스타브\'은 마법 20 데미지를 받았다!!\n";
					ai.Damage(20);
				}
				else {
					cout << "실패!\n";
					cout << "\'시미야 진\'는 마법 10 데미지를 받았다!!\n";
					character.Damage(10);
				}
			}
			else {
				cout << "\'시미야 진\'는 마법 10 데미지를 받았다!!\n";
				ai.Damage(10);
			}
		}
		if (ai_answer == "바위") {
			cout << "힘 바위를 냈다!\n";
			Sleep(1000);
			cout << "상대에게 10의 데미지!\n";
			if (answer == "보") {
				cout << "\'구스타브\'의 카운터!!\n";
				if (counter == "힘") {
					Sleep(1000);
					cout << "성공!\n";
					cout << "\'구스타브\'은 20 데미지를 받았다!!\n";
					ai.Damage(20);
				}
				else {
					cout << "실패!\n";
					cout << "\'시미야 진\'는 10 데미지를 받았다!!\n";
					character.Damage(10);
				}
			}
			else {
				cout << "\'시미야 진\'는 10 데미지를 받았다!!\n";
				ai.Damage(10);
			}
		}
		cout << "내 체력" << ' ' << character.showEnergy() << '\n';
		cout << "구스타브의 체력" << ' ' << ai.showEnergy() << '\n';
		if (character.showEnergy() <= 0) {
			cout << "졌다!\n";
			break;
		}
		else if (ai.showEnergy() <= 0) {
			cout << "이겼다!\n";
			break;
		}
		Sleep(5000);
		system("cls");
	}
	return 0;
}