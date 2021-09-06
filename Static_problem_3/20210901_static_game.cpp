#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>
using namespace std;

class Game {
private:
	double energy = 100;
	static int life; //static�� Ȱ���� �� ���߽��ϴ� T^T ���� �ǹ̰� �����
public:
	double Damage(int dam);
	static void Die();
	void lifeRecharge();
	int showEnergy();
};

int Game::life = 1;

void Game::Die() {
	life--;
	cout << "������ 1 �����Ͽ� " << life << "�� �Ǿ����ϴ�." << "\n\n";
}

double Game::Damage(int dam) {
	double damaged = 0;
	if (energy > 0) {
		damaged += dam;
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

void Game::lifeRecharge() { // ��� �Ƚ���ϴ�
	cout << "�������� �����Ͻðڽ��ϱ�? (��: 1/�ƴϿ�: 2)\n";
	int N;
	cin >> N;
	if (N == 1) {
		cout << "���� ������ ������ �Ա��Դϴ�.\n";
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
	cout << "������ ������������ �����մϴ�.\n";
	Sleep(1000);
	cout << "����� �̸��� �˷��ּ��� >> "; 
	string noMean;
	cin >> noMean;
	cout << "\'�ù̾� ��\' ��.. ";
	Sleep(1000);
	cout << "���� �̸��̱���..\n";
	Sleep(1000);
	cout << "���� ��븦 ��û�ϰڽ��ϴ�.\n";
	Sleep(5000);
	cout << "\'����Ÿ��\'";
	Sleep(1000);
	cout << " ���� �ʴ�Ǿ����ϴ�.\n";
	Sleep(1000);
	cout << "�׷� �ε� �̾߱���� ��ȣ�� �ֱ�";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".\n";
	Sleep(1000);
	system("cls");
	cout << "������ ��������!\n";
	string answer;
	string counter;
	string ai_answer;
	string ai_counter;
	Game character;
	Game ai;
	while (true) {
		Sleep(1000);
		cout << "\'�ù̾� ��\'�� ��!\n";
		Sleep(1000);
		cout << "����, ����, �� �߿� �����ض� >> ";
		cin >> answer;
		if (answer == "����") {
			cout << "���� ������ �����ߴ�!\n";
		}
		else if (answer == "����") {
			cout << "�� ������ �����ߴ�!\n";
		}
		else if (answer == "��") {
			cout << "���� �����ߴ�!\n";
			cout << "���� ���ڱ��ΰ� �� ���ڱ��ΰ� �Է�: (����/��) >> ";
			cin >> counter;
			if (counter == "����") {
				cout << "���� ���ڱ��!\n";
			}
			else if (counter == "��") {
				cout << "�� ���ڱ��!\n";
			}
			else {
				cout << "NULL�� �����ߴ�!\n";
				cout << "ġ������ ���� �ý��� �߰�!\n";
				cout << "���α׷��� ������ �����մϴ�.\n";
				return 0;
			}
		}
		else if (answer == "��") {
			cout << "���� �����ߴ�!\n";
		}
		else {
			cout << "NULL�� �����ߴ�!\n";
			cout << "ġ������ ���� �ý��� �߰�!\n";
			cout << "���α׷��� ������ �����մϴ�.\n";
			return 0;
		}
		cout << "\'����Ÿ��\'�� ��!!\n";
		cout << "��ٸ��� ��";
		for (int i = 0; i < 3; i++) {
			cout << ". ";
			Sleep(2000);
		}
		int suntack = rand() % 4 + 1;
		switch (suntack) {
		case 1:
			ai_answer = "����";
			break;
		case 2:
			ai_answer = "����";
			break;
		case 3:
			ai_answer = "��";
			ai_counter = "����";
			break;
		case 4:
			ai_answer = "��";
			ai_counter = "��";
			break;
		default:
			break;
		}
		cout << "�ǰ�!\n";
		Sleep(1000);
		cout << "\'�ù̾� ��\'�� ";
		Sleep(1000);
		if (answer == "����") {
			cout << "���� ������ �´�!\n";
			Sleep(1000);
			cout << "��뿡�� ���� 10�� ������!\n";
			if (ai_answer == "��") {
				cout << "\'����Ÿ��\'�� ī����!!\n";
				if (ai_counter == "����") {
					Sleep(1000);
					cout << "����!\n";
					cout << "\'�ù̾� ��\'�� ���� 20 �������� �޾Ҵ�!!\n";
					character.Damage(20);
				}
				else {
					cout << "����!\n";
					cout << "\'����Ÿ��\'�� ���� 10 �������� �޾Ҵ�!!\n";
					ai.Damage(10);
				}
			}
			else {
				cout << "\'����Ÿ��\'�� ���� 10 �������� �޾Ҵ�!!\n";
				ai.Damage(10);
			}
		}
		if (answer == "����") {
			cout << "�� ������ �´�!\n";
			Sleep(1000);
			cout << "��뿡�� 10�� ������!\n";
			if (ai_answer == "��") {
				cout << "\'����Ÿ��\'�� ī����!!\n";
				if (ai_counter == "��") {
					Sleep(1000);
					cout << "����!\n";
					cout << "\'�ù̾� ��\'�� 20 �������� �޾Ҵ�!!\n";
					character.Damage(20);
				}
				else {
					cout << "����!\n";
					cout << "\'����Ÿ��\'�� 10 �������� �޾Ҵ�!!\n";
					ai.Damage(10);
				}
			}
			else {
				cout << "\'����Ÿ��\'�� 10 �������� �޾Ҵ�!!\n";
				ai.Damage(10);
			}
		}
		else if (answer == "��") {
			cout << " \'����Ÿ��\' ���� ���� ����\n";
			Sleep(1000);
			cout << "ȿ���� �����ߴ�! ���� 100�� ���ظ� �Ծ���!\n";
			ai.Damage(100);
		}
		Sleep(1000);
		cout << "\'����Ÿ��\'�� ";
		Sleep(1000);
		if (ai_answer == "����") {
			cout << "���� ������ �´�!\n";
			Sleep(1000);
			cout << "��뿡�� ���� 10�� ������!\n";
			if (answer == "��") {
				cout << "\'�ù̾� ��\'�� ī����!!\n";
				if (counter == "����") {
					Sleep(1000);
					cout << "����!\n";
					cout << "\'����Ÿ��\'�� ���� 20 �������� �޾Ҵ�!!\n";
					ai.Damage(20);
				}
				else {
					cout << "����!\n";
					cout << "\'�ù̾� ��\'�� ���� 10 �������� �޾Ҵ�!!\n";
					character.Damage(10);
				}
			}
			else {
				cout << "\'�ù̾� ��\'�� ���� 10 �������� �޾Ҵ�!!\n";
				ai.Damage(10);
			}
		}
		if (ai_answer == "����") {
			cout << "�� ������ �´�!\n";
			Sleep(1000);
			cout << "��뿡�� 10�� ������!\n";
			if (answer == "��") {
				cout << "\'����Ÿ��\'�� ī����!!\n";
				if (counter == "��") {
					Sleep(1000);
					cout << "����!\n";
					cout << "\'����Ÿ��\'�� 20 �������� �޾Ҵ�!!\n";
					ai.Damage(20);
				}
				else {
					cout << "����!\n";
					cout << "\'�ù̾� ��\'�� 10 �������� �޾Ҵ�!!\n";
					character.Damage(10);
				}
			}
			else {
				cout << "\'�ù̾� ��\'�� 10 �������� �޾Ҵ�!!\n";
				ai.Damage(10);
			}
		}
		cout << "�� ü��" << ' ' << character.showEnergy() << '\n';
		cout << "����Ÿ���� ü��" << ' ' << ai.showEnergy() << '\n';
		if (character.showEnergy() <= 0) {
			cout << "����!\n";
			break;
		}
		else if (ai.showEnergy() <= 0) {
			cout << "�̰��!\n";
			break;
		}
		Sleep(5000);
		system("cls");
	}
	return 0;
}