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
	cout << "생명이 1 감소하여 " << life << "이 되었습니다." << "\n\n";
}

double Game::Damage() {
	double damaged = 0;
	if (energy > 0) {
		damaged += rand() % 100;
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

void Game::lifeRecharge() {
	cout << "라이프를 충전하시겠습니까? (예: 1/아니오: 2)\n";
	int N;
	cin >> N;
	if (N == 1) {
		cout << "결제 수단은 무통장 입금입니다.\n";
	}
}

Game::Game()
{
	cout << "에너지가 " << energy << " 이며, 생명이 " << life << "인 캐릭터가 만들어졌습니다.\n";
}

int main()
{
	srand((unsigned int)time(NULL));
	return 0;
}