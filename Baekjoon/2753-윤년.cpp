#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int a;
	bool b = false;

	cin >> a;

	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
		b = true;

	cout << b;

	return 0;
}