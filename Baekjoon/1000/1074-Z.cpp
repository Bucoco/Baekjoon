#include <iostream>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	std::ios::sync_with_stdio(false);

	int n, r, c, a = 0, b = 0, cnt = 0;

	cin >> n >> r >> c;
	int s = 1;
	while (n--) {
		s <<= 1;
	}

	while (s >>= 1) {
		if (r >= a + s) {
			cnt += s * s * 2;
			a += s;
		}
		if (c >= b + s) {
			cnt += s * s;
			b += s;
		}
	}

	cout << cnt;
	return 0;
}