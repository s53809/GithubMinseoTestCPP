#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Movie {
private:
	string name;
	float score;
public:
	Movie(string name, float score) {
		this->name = name;
		this->score = score;
	}
	~Movie() {}

	

	void print() {
		cout << "Movie name : " << name << '\n';
		cout << "Movie score : " << score << '\n';
	}
};

int main() {
	vector<Movie> v;
	int count;
	string name;
	float score;
	cout << "input count : ";
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> name >> score;
		Movie x(name, score);
		v.push_back(x);
	}
	for (int i = 0; i < count; i++) {
		v[i].print();
	}
}