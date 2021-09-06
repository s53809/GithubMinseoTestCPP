#include <iostream>
#include<cstdlib>
#include<ctime>
#include <string>
#include <Windows.h>
#include <conio.h>
using namespace std;

#define MAX_HP 150
#define MAX_ATK 20
#define MAX_DFS 10
#define MAX_ENERGY 100
#define MAX_POTION 3

class Game {
private:
	string name;
	int atk;
	int dfs;
	float energy;
	int potion;
public:
	static float HP;
	Game(int h, int a, int d, int e);
	void Stat(float eHp, int eAtk, int eDfs, float mEhp, string eName);
	void Damage(int dmg, string eName);
	int attack(int eDfs, string eName);
	bool live();
	void play(float* eHp, int eAtk, int eDfs, string eName);
};
float Game::HP = MAX_HP;
Game::Game(int h = MAX_HP, int a = MAX_ATK, int d = MAX_DFS, int e = MAX_ENERGY)
{
	cout << "이름을 입력해 주세요: ";
	cin >> name;
	HP = h;
	atk = a;
	dfs = d;
	energy = e;
	potion = MAX_POTION;
}

void Game::Stat(float eHp, int eAtk, int eDfs, float mEhp, string eName) {
	cout << "<" << name << '>' << endl;
	cout << "생명력: ";
	float i;
	for (i = 0.0f; i < HP; i += (MAX_HP / 10)) {
		cout << "♥";
	}
	for (i; i < MAX_HP; i += (MAX_HP / 10)) {
		cout << "♡";
	}
	cout << HP << '/' << MAX_HP << endl;
	cout << "에너지: ";
	for (i = 0.0f; i < energy; i += MAX_ENERGY / 10) {
		cout << "■";
	}
	for (i; i < MAX_ENERGY; i += MAX_ENERGY / 10) {
		cout << "□";
	}
	cout << energy << '/' << MAX_ENERGY << endl;
	cout << "공격력: " << atk << endl;
	cout << "방어력: " << dfs << endl;
	cout << "포션 갯수: " << potion << endl << endl;
	cout << '<' << eName << ">\n";
	cout << "생명력: ";

	for (i = 0.0f; i < eHp - 1.0f; i += (float)mEhp / 10) {
		cout << "♥";
	}
	for (i; i < mEhp - 1.0f; i += (float)mEhp / 10) {
		cout << "♡";
	}
	cout << eHp << '/' << mEhp << endl;
	cout << "공격력: " << eAtk << endl;
	cout << "방어력: " << eDfs << endl << endl;
	cout << "--------------------\n";
}

void Game::Damage(int dmg, string eName) {
	int hit = dmg - dfs;
	if (hit < 0) hit = 0;
	HP -= hit;
	cout << "-" << eName << "의 공격으로 HP가 " << hit << "만큼 감소하였습니다.-\n";
}

int Game::attack(int eDfs, string eName) {
	int att = atk - eDfs;
	if (att < 0) att = 0;
	cout << "\n-" << eName << "에게 " << att << "만큼의 피해를 입혔습니다.-\n";
	return att;
}

bool Game::live() {
	return HP > 0;
}

void Game::play(float* eHp, int eAtk, int eDfs, string eName) {
	cout << "<" << name << ">\n";
	cout << "[1] <공격> 에너지 소모: " << MAX_ENERGY / 5 << endl;
	cout << "[2] <막기> 에너지 소모: " << MAX_ENERGY / 10 << endl;
	cout << "[3] <쉬기> 에너지 " << MAX_ENERGY / 4 << "회복\n";
	cout << "[4] <포션사용> HP " << MAX_HP / 4 << "회복\n";
	cout << "[5] <포기>\n";
	int engre = MAX_ENERGY / 10;
	while (1) {
		int input = 10;
		while (input < 1 || input > 5) {
			cout << "선택해 주세요: ";
			cin >> input;
		}
		switch (input)
		{
		case 1:
			if (energy < MAX_ENERGY / 5) {
				cout << "에너지가 부족합니다!\n";
				break;
			}
			else {
				*eHp -= (float)attack(eDfs, eName);
				if (*eHp > 0) Damage(eAtk, eName);
				energy -= MAX_ENERGY / 5;
				return;
			}
			break;
		case 2:
			if (energy < MAX_ENERGY / 10) {
				cout << "에너지가 부족합니다!\n";
				break;
			}
			else {
				cout << "적의 공격을 막았습니다.\n";
				energy -= MAX_ENERGY / 10;
				return;
			}
			break;
		case 3:
			Damage(eAtk, eName);
			energy += MAX_ENERGY / 4;
			if (energy > MAX_ENERGY) energy = MAX_ENERGY;
			return;
		case 4:
			if (potion <= 0) cout << "남은 포션이 없습니다!\n";
			else if (HP == MAX_HP) cout << "HP가 최대 입니다!\n";
			else if (HP + MAX_HP / 4 > MAX_HP) {
				cout << "-HP " << HP + MAX_HP / 4 - MAX_HP << "회복-\n";
				HP = MAX_HP;
				Damage(eAtk, eName);
				potion--;
				return;
			}
			else {
				cout << "-HP " << MAX_HP / 4 << "회복-\n";
				HP += MAX_HP / 4;
				Damage(eAtk, eName);
				potion--;
				return;
			}
			break;
		case 5:
			char yorn;
			cout << "포기하시겠습니까?(y) ";
			cin >> yorn;
			if (yorn == 'y' || yorn == 'Y') {
				HP -= HP;
				return;
			}
		default:
			break;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	string eName[10] = { "과제", "시험", "졸음", "희찬", "시우", "원신", "민트초코", "솔로", "커플", "사감쌤" };
	Game p1(MAX_HP, MAX_ATK, MAX_DFS, MAX_ENERGY);
	int eN = rand() % 10;
	string ee(eName[eN]);
	float eHp = rand() % MAX_HP / 2 + 50;
	int eAtk = rand() % MAX_ATK / 3 + MAX_ATK;
	int eDfs = rand() % MAX_DFS / 2 + MAX_DFS / 2;
	float mEhp = eHp;
	cout << "앗 야생의 " << ee << "(이)가 나타났다!\n";
	cout << "press any key";
	_getch();
	system("cls");
	while (p1.live() && eHp > 0) {
		p1.Stat(eHp, eAtk, eDfs, mEhp, ee);
		p1.play(&eHp, eAtk, eDfs, ee);
		cout << "press ant key";
		_getch();
		system("cls");
	}
	if (!p1.live()) cout << "사망하셨습니다!\n";
	else cout << "적을 물리치셨습니다!\n";
	return 0;
}