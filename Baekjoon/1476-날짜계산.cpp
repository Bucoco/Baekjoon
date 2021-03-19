#include <iostream>
using namespace std;

int main() {
	int e, s, m;
	int year = 0;
	cin >> e >> s >> m;
	while (1) {
		int a, b, c;
		a = year % 15 + 1;
		b = year % 28 + 1;
		c = year % 19 + 1;
		year++;
		if (a == e && b == s && c == m)
			break;
	}

	cout << year;
	return 0;

}