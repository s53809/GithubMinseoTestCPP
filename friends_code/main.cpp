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
	cout << "�̸��� �Է��� �ּ���: ";
	cin >> name;
	HP = h;
	atk = a;
	dfs = d;
	energy = e;
	potion = MAX_POTION;
}

void Game::Stat(float eHp, int eAtk, int eDfs, float mEhp, string eName) {
	cout << "<" << name << '>' << endl;
	cout << "�����: ";
	float i;
	for (i = 0.0f; i < HP; i += (MAX_HP / 10)) {
		cout << "��";
	}
	for (i; i < MAX_HP; i += (MAX_HP / 10)) {
		cout << "��";
	}
	cout << HP << '/' << MAX_HP << endl;
	cout << "������: ";
	for (i = 0.0f; i < energy; i += MAX_ENERGY / 10) {
		cout << "��";
	}
	for (i; i < MAX_ENERGY; i += MAX_ENERGY / 10) {
		cout << "��";
	}
	cout << energy << '/' << MAX_ENERGY << endl;
	cout << "���ݷ�: " << atk << endl;
	cout << "����: " << dfs << endl;
	cout << "���� ����: " << potion << endl << endl;
	cout << '<' << eName << ">\n";
	cout << "�����: ";

	for (i = 0.0f; i < eHp - 1.0f; i += (float)mEhp / 10) {
		cout << "��";
	}
	for (i; i < mEhp - 1.0f; i += (float)mEhp / 10) {
		cout << "��";
	}
	cout << eHp << '/' << mEhp << endl;
	cout << "���ݷ�: " << eAtk << endl;
	cout << "����: " << eDfs << endl << endl;
	cout << "--------------------\n";
}

void Game::Damage(int dmg, string eName) {
	int hit = dmg - dfs;
	if (hit < 0) hit = 0;
	HP -= hit;
	cout << "-" << eName << "�� �������� HP�� " << hit << "��ŭ �����Ͽ����ϴ�.-\n";
}

int Game::attack(int eDfs, string eName) {
	int att = atk - eDfs;
	if (att < 0) att = 0;
	cout << "\n-" << eName << "���� " << att << "��ŭ�� ���ظ� �������ϴ�.-\n";
	return att;
}

bool Game::live() {
	return HP > 0;
}

void Game::play(float* eHp, int eAtk, int eDfs, string eName) {
	cout << "<" << name << ">\n";
	cout << "[1] <����> ������ �Ҹ�: " << MAX_ENERGY / 5 << endl;
	cout << "[2] <����> ������ �Ҹ�: " << MAX_ENERGY / 10 << endl;
	cout << "[3] <����> ������ " << MAX_ENERGY / 4 << "ȸ��\n";
	cout << "[4] <���ǻ��> HP " << MAX_HP / 4 << "ȸ��\n";
	cout << "[5] <����>\n";
	int engre = MAX_ENERGY / 10;
	while (1) {
		int input = 10;
		while (input < 1 || input > 5) {
			cout << "������ �ּ���: ";
			cin >> input;
		}
		switch (input)
		{
		case 1:
			if (energy < MAX_ENERGY / 5) {
				cout << "�������� �����մϴ�!\n";
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
				cout << "�������� �����մϴ�!\n";
				break;
			}
			else {
				cout << "���� ������ ���ҽ��ϴ�.\n";
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
			if (potion <= 0) cout << "���� ������ �����ϴ�!\n";
			else if (HP == MAX_HP) cout << "HP�� �ִ� �Դϴ�!\n";
			else if (HP + MAX_HP / 4 > MAX_HP) {
				cout << "-HP " << HP + MAX_HP / 4 - MAX_HP << "ȸ��-\n";
				HP = MAX_HP;
				Damage(eAtk, eName);
				potion--;
				return;
			}
			else {
				cout << "-HP " << MAX_HP / 4 << "ȸ��-\n";
				HP += MAX_HP / 4;
				Damage(eAtk, eName);
				potion--;
				return;
			}
			break;
		case 5:
			char yorn;
			cout << "�����Ͻðڽ��ϱ�?(y) ";
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
	string eName[10] = { "����", "����", "����", "����", "�ÿ�", "����", "��Ʈ����", "�ַ�", "Ŀ��", "�簨��" };
	Game p1(MAX_HP, MAX_ATK, MAX_DFS, MAX_ENERGY);
	int eN = rand() % 10;
	string ee(eName[eN]);
	float eHp = rand() % MAX_HP / 2 + 50;
	int eAtk = rand() % MAX_ATK / 3 + MAX_ATK;
	int eDfs = rand() % MAX_DFS / 2 + MAX_DFS / 2;
	float mEhp = eHp;
	cout << "�� �߻��� " << ee << "(��)�� ��Ÿ����!\n";
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
	if (!p1.live()) cout << "����ϼ̽��ϴ�!\n";
	else cout << "���� ����ġ�̽��ϴ�!\n";
	return 0;
}