#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	b += c % 60;
	a += c / 60;

	if (b >= 60) {
		b %= 60;
		a++;
	}

	if (a >= 24)
		a %= 24;

	cout << a << " " << b;
	return 0;

}