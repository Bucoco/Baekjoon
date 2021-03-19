#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int a, b, c;

	while (true) {
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		cin >> c;
		if (b > c)
			swap(b, c);
		if (!c)
			break;
		if (c * c == a * a + b * b)
			cout << "right\n";
		else
			cout << "wrong\n";
	}

	return 0;
}