#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game {
private:
	double energy = 100;
	static int life;
public:
	Game();
	double Damage();
	static void Die();
	void lifeRecharge();
};

int Game::life = 10;

void Game::Die() {
	life--;
	cout << "������ 1 �����Ͽ� " << life << "�� �Ǿ����ϴ�." << "\n\n";
}

double Game::Damage() {
	double damaged = 0;
	if (energy > 0) {
		damaged += rand() % 100;
		energy -= damaged;
		cout << "�������� " << damaged << " �����Ͽ� " << energy << " �� �Ǿ����ϴ�.\n";
		if (energy < 0) {
			life--;
			energy = 100;
			cout << "������ 1 �����Ͽ� " << life << "�� �Ǿ����ϴ�." << "\n\n";

		}
	}
	return energy;
}

void Game::lifeRecharge() {
	cout << "�������� �����Ͻðڽ��ϱ�? (��: 1/�ƴϿ�: 2)\n";
	int N;
	cin >> N;
	if (N == 1) {
		cout << "���� ������ ������ �Ա��Դϴ�.\n";
	}
}

Game::Game()
{
	cout << "�������� " << energy << " �̸�, ������ " << life << "�� ĳ���Ͱ� ����������ϴ�.\n";
}

int main()
{
	srand((unsigned int)time(NULL));
	return 0;
}