#include <iostream>
using namespace std;

int main() {
	int n, jm, hs;
	int round = 0;
	cin >> n >> jm >> hs;

	while (jm != hs) {
		jm = ++jm / 2;
		hs = ++hs / 2;
		round++;
	}
	cout << round;
	return 0;
}