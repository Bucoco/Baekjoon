#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int a, b = 0;
	for (int i = 0;i < 5;i++) {
		cin >> a;
		b += a * a;
	}

	cout << b % 10;

	return 0;
}