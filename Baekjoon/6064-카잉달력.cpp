#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	if (a < b)
		swap(a, b);
	while (b != 0) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int t, m, n, x, y, year;
	int cx, cy;
	cin >> t;
	while (t--) {
		year = 1;
		cin >> m >> n >> x >> y;
		if (m > n) {
			swap(m, n);
			swap(x, y);
		}
		year = cx = cy = x;
		int lcm = m * n / gcd(m, n);
		while (cx != x || cy != y) {
			if (year>lcm) {
				year = -1;
				break;
			}
			cy += m;
			if (cy!=n) {
				cy %= n;
			}
			year += m;
		}
		cout << year << "\n";
	}
	return 0;
}