#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int a, b;
	string c;
	cin >> a >> b >> c;

	if (c.back() - '0' & 1) {
		a ^= b;
	}
	cout << a;

	return 0;
}