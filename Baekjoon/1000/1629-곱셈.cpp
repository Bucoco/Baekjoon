#include <iostream>
using namespace std;

long long a, b, c;

long long cal(long long  a, long long b) {
	if (!b)
		return 1;
	if (b & 1)
		return (a * cal(a, b - 1) % c) % c;
	return cal((a * a) % c, b / 2) % c;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> a >> b >> c;

	cout << cal(a, b);

	return 0;
}