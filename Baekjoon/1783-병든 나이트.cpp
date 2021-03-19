#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	std::ios::sync_with_stdio(false);

	int n, m, cnt;
	cin >> n >> m;

	if (n == 1) {
		cout << 1;
	}
	else if (n == 2) {
		if (m > 8)
			cout << 4;
		else
			cout << (m + 1) / 2;
	}
	else {
		if (m >= 7)
			cout << m - 2;
		else if (m <= 3)
			cout << m;
		else
			cout << 4;
	}

	return 0;
}