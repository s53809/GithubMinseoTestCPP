#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Movie {
public:
	string movieName;
	int starGetsu;
};

int main() {
	vector<Movie> x;
	x.resize(1);
	int i = 0;
	while (true) {
		string a;
		int b;
		cin >> a >> b;
		if (a == "-1" && b == -1) {
			break;
		}
		x[i].movieName = a;
		x[i].starGetsu = b;
		i++;
		x.resize(i);
	}
	for (int i = 0; i < x.size(); i++) {
		cout << x[i].movieName << ' ' << x[i].starGetsu << '\n';
	}
	return 0;
}